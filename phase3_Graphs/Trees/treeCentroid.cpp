#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/* Centroid of Tree:
 * A node at which if we root the tree, the size of each subtrees will be <= N/2
 * Centres and centroid aren't the same. Notice how earlier depends upon length, but this depends upon the no. of nodes.
 * There could be atmax 2 centroids.
 * 
 * Implementation:
 * Notice how there'll be exactly one subtree with size >n/2 if a node will not be centroid.
 * Recursively go into that subtree to find centroid. Think why!
*/

int n;
vector<vector<int>> adj;
vector<int> subtreeSize;

void dfs(int node, int par){

    subtreeSize[node]=1;
    for(auto v: adj[node]){
        if( v != par ){
            dfs(v, node);
            subtreeSize[node] += subtreeSize[v];
        }
    }
}


int getCentroid(int node, int par){

    for(auto v: adj[node]){
        if(v!=par && subtreeSize[v] > n/2){
            return getCentroid(v, node);
        }
    }
    return node;
}

void solve(){
    cin>>n;
    adj.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    subtreeSize.resize(n+1, 0);
    dfs(1, 0);      // to calculate the subtree sizes rooted at 1

    int centroid = getCentroid(1, 0);
    cout << centroid << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}