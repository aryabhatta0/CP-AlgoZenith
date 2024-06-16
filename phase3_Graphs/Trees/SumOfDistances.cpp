// https://maang.in/problems/Sum-of-Distances-430?resourceUrl=cs99-cp522-pl3601-rs430
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n;
vector<vector<int>> adj;
vector<int> subtreeSize;

/* Find sum of distance b/w all possible pair of node
 * Idea: EDGE CONTRIBUTION TECHNIQUE
 * since ans would be sum of some edges:
 *  Count how many times an edge will appear in all pairs
*/

void dfs(int node, int par){

    subtreeSize[node]=1;
    for(auto v: adj[node]){
        if(v != par){
            dfs(v, node);
            subtreeSize[node] += subtreeSize[v];
        }
    }
}

void solve(){
    cin>>n;
    adj.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    subtreeSize.resize(n+1, -1);
    dfs(1, 0);

    // edge contribution
    ll sum=0;
    for(int i=1; i<=n; i++){
        // edge ending at i
        // all pairs where both node is present at different side of edge contributes this edge
        sum += 1LL * subtreeSize[i] * (n-subtreeSize[i]);
    }
    cout << sum << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}