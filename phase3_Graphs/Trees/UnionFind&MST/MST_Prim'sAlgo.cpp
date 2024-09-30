// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45/
#include<bits/stdc++.h>
using namespace std;

/** We need to find minimum spanning tree (min cost of path that'd traverse all nodes of graph)

- Start with an arbitrary node (MST is empty at start)
- Greedily try to select a node which would take shortest cost to add it in the MST
- Use pq {wt, node}
 */

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // min-heap     {wt, node}
        // wt is the cost it'll take to add 'node' in the MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        vector<int> vis(V, 0);
        
        int ans=0;
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            if(!vis[it.second]){
                // visit curr
                vis[it.second]=1;
                ans+=it.first;      // it.S is being visited through this edge
                // add it's neighbours
                for(auto v: adj[it.second]){
                    if(!vis[v[0]]) pq.push({v[1], v[0]});
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends