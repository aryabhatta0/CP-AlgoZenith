// https://maang.in/problems/Creating-Teams-193?resourceUrl=cs99-cp522-pl3548-rs193
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n, m;
vector<vector<int>> adj;
vector<int> team;   // also act as vis array
bool poss=1;

void dfs(int sc, int ch){
    team[sc]=ch;

    for(auto v: adj[sc]){
        if(team[v]==ch) {
            poss=0;
            return;
        }
        else if(team[v]==0){ // not visited
            dfs(v, 3-ch);
            if(!poss) return;
        }
    }
}

void solve(){
    cin>>n>>m;
    adj.resize(n+1);
    int a, b;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    team.assign(n+1, 0);
    for(int i=1; i<=n; i++){
        if(team[i]==0)
            dfs(i, 1);
        if(!poss) break;
    }

    if(poss) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}