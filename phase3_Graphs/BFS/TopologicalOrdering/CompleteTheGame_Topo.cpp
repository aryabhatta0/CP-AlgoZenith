// https://maang.in/problems/Complete-the-Game-432?resourceUrl=cs99-cp522-pl3550-rs432

/** 3 ways:
 * DFS Topo:    _/ easy.
 * BFS Topo:    why WA?
 * Recursive DP:    ToDo
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Let dp[v] denote the number of paths reaching v. We can see, dp[v]= sum of all dp[u], s.t. u → v edge exists.
// if we process the states in an order that guarantees for every edge u → v that u is processed before v
// => Topological Sorting

int n, m;
vector<vector<int>> adj;

// WHAT IF WE USE RECURSIVE DP?
// dp[i]: no. of way for i->n
// dp[i] = sum of dp of all its neighbour 
// I wanna use, but already given enough time huh

// Why is this giving WA?
// The soln has used backEdge !
// Kahn's
// we need to process nodes in a way that guarantees topo sort
void solve_WA(){
    cin>>n>>m;
    adj.resize(n+1);
    int a,b;

    vector<int> inDeg(n+1, 0);
    vector<ll> freq(n+1, 0);       // that's basically DP that stores no. of ways to reach the node from 1
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        inDeg[b]++;
    }

    queue<int> q;
    // for(int i=1; i<=n; i++){
    //     if(inDeg[i]==0) {
    //         q.push(i);
    //         freq[i]=1;
    //     }
    // }
    q.push(1);
    freq[1]=1;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        for(auto v: adj[curr]){
            freq[v] = (freq[v]+freq[curr])%mod;

            inDeg[v]--;
            if(inDeg[v]==0) {
                q.push(v);
            }
        }
    }

    cout << freq[n] << "\n";
}

///////////////////////////////////////////////////////////////////////////////// mine

vector<bool> vis;
vector<int> topo;

void dfs(int u){
    vis[u]=1;

    for(auto v: adj[u]){
        if(!vis[v]) dfs(v);
    }

    topo.push_back(u);
}

void solve(){
    cin>>n>>m;
    adj.resize(n+1);
    int a,b;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
    }

    // find topo
    vis.assign(n+1, 0);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());

    // this has to be done in topo order, and not using the bfs exploration
    vector<ll> freq(n+1, 0);   // no. of ways a node is reached starting from 1
    // vector<bool> vis(n+1, 0);
    // queue<int> q;
    // q.push(1);
    // vis[1]=1;
    // while(!q.empty()){
    //     auto curr = q.front();
    //     q.pop();

    //     for(auto v: adj[curr]){
    //         freq[v] = (freq[v]+1)%mod;
    //         if(vis[v]==0){
    //             q.push(v);
    //             vis[v]=1;
    //         }
    //     }
    // }

    freq[1]=1;
    for(auto curr: topo){
        for(auto v: adj[curr]){
            // freq[v]++;
            // freq[v] = (freq[v]+1)%mod;
            // freq[v] = max(freq[curr], (freq[v]+freq[curr])%mod);
            freq[v] = (freq[v]+freq[curr])%mod;
        }
    }

    cout << freq[n] << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}