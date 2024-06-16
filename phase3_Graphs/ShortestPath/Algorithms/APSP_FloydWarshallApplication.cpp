// https://maang.in/problems/All-Pairs-Shortest-Path-431?resourceUrl=cs99-cp522-pl3596-rs431
// All Pairs Shortest Path
/*
We have given an adjacency representation of a directed weighted graph and an array of vertices. At each iteration, a vertex is removed from the graph. Vertices are removed in the order given in the array. When the vertex is removed, all the edges that go in and out are also removed. 
Print the sum of all pairs shortest path just before each iteration.
*/

// Tough one, but just wow 🔥

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int INF=1e9;

void solve(){
    // Floyd Warshall
    int n; cin>>n;
    vector<vector<int>> matrix(n+1, vector<int>(n+1, INF));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin>>matrix[i][j];
    }

    vector<int> x(n+1);
    for(int i=1; i<=n; i++) cin>>x[i];

    // we need to find all pair shortest path sum before each x[k] removal 
    // so at x[k], we want APSP sum using nodes x[i]; i= k, k+1, .... , n

    // Remember the Floyd Warshall Concept?
    // that at each iter k, we calculate APSP for all pairs using nodes 1....k

    // so let's traverse the nodes in opposite order of reversal i.e, x[i]; i=n, ....... , 1
    // and continue updating APSP paths as we do in Floyd Warshall

    vector<ll> ans;
    for(int k=n; k>=1; k--){  // x[k] will be the intermediate node at a iter
        // update all pair shortest paths
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][x[k]] + matrix[x[k]][j]);
            }
        }

        // add sum of the APSP's to ans
        // we want only the sum of pairs using x[i]; i=k, k+1, ...... , n
        // others will be removed a/c to Q
        ll sum=0;
        for(int i=k; i<=n; i++){
            for(int j=k; j<=n; j++)
                sum+= matrix[x[i]][x[j]];
        }
        ans.push_back(sum);
    }

    // the Q asked u to remove the node in x[1]; i=1, .... , n order
    // but we rather traversed the pairs through intermediates in x[i]; i=n , ..... , 1 order
    // so, reverse the ans now
    reverse(ans.begin(), ans.end());
    for(auto it: ans) cout << it << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}