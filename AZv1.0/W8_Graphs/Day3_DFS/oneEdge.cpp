#include <bits/stdc++.h>
using namespace std;
#define ll long long

// The prb is to find ways to add a edge to reduce the connected components
// Idea is to find the size of each connected component and use PnC to find the answer

// ToDo: Space optimized - Can be solved without storing all the sizes, adding to ans while dfs only

int n, m;
vector<vector<int>> Adj;
vector<bool> vis;
vector<int> componentSize;
int cnt = 0;

void dfs(int u){
    vis[u] = true;
    componentSize[cnt]++;
    for(auto v: Adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void solve(){
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
            /** could have calc sqsum for ans here only **/
            // space optimized
        }
    }

    // cout<<cnt<<"\n";
    // cout << "componentSize: ";
    // for(int i=1; i<=n; i++){
    //     cout<<componentSize[i]<<" ";
    // } cout<<"\n";

    if(cnt == 1){
        cout << "0\n";
        return;
    }

    // Ans will be sum of all possible pairs of componentSize
    ll ans = 0;
    // for(int i=1; i<=n; i++){
    //     if(componentSize[i]==0) break;
    //     for(int j=i+1; j<=n; j++){
    //         if(componentSize[j]==0) break;
    //         ans += 1LL*componentSize[i]*componentSize[j];
    //     }
    // }

    // prefix sum
    vector<ll> prefixSum(n+1, 0);
    for(int i=1; i<=n; i++){
        prefixSum[i] = prefixSum[i-1] + componentSize[i];
    }
    // cout << "prefixSum: ";
    // for(int i=1; i<=n; i++) cout<<prefixSum[i]<<" "; cout<<"\n";

    ans = 0;
    for(int i=1; i<=n; i++){
        if(componentSize[i]==0) break;
        ans += 1LL*componentSize[i]*(prefixSum[n]-prefixSum[i]);
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    Adj.resize(n+1);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    vis.resize(n+1, false);
    componentSize.resize(n+1, 0);

    solve();
    
    return 0;
}