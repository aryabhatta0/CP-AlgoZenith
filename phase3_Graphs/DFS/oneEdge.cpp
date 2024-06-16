#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// The prb is to find ways to add a edge to reduce the connected components
// Idea is to find the size of each connected component and use PnC to find the answer

// Optimization: PnC calc could have avoided if we simplify the expression in terms of squares, and calculate it early only.

int n,m;
vector<vector<int>> adj;
vector<int> marked;     // stores comp id
vector<int> compSize;   // ith comp size

void dfs(int sc, int flag){
    marked[sc]=flag;
    compSize[flag]++;

    for(auto v: adj[sc]){
        if(!marked[v]){
            dfs(v, flag);
        }
    }
}

void solve(){
    cin>>n>>m;
    int u, v;
    adj.resize(n+1);
    marked.resize(n+1, 0);
    compSize.resize(n+1, 0);
    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt=0;
    for(int i=1; i<=n; i++){
        if(!marked[i]){
            cnt++;
            dfs(i, cnt);
        }
    }

    // cout << "#CC=" << cnt << "\n";
    // for(int i=1; i<=n; i++) cout << "comp" << i << ":" << compSize[i] << "\t";
    // cout << "\n";

    // prefix sum
    vector<int> pref(n+1, 0);
    for(int i=1; i<=n; i++)
        pref[i] = pref[i-1] + compSize[i];

    ll ans = 0;
    for(int i=1; i<=n; i++){
        if(compSize[i]==0) break;
        ans += 1LL*compSize[i] * (pref[n]-pref[i]);
    }
    cout << ans << "\n";
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}