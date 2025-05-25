// https://practice.geeksforgeeks.org/problems/mother-vertex/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited){
        visited[node] = true;
        for(auto child: adj[node]){
            if(!visited[child]){
                dfs(child, adj, visited);
            }
        }
    }

    // the first node jiske liye saara node vis ho jayega, can be a mother node
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
        vector<bool> visited(V, false);
        int lastNode = 0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                lastNode = i;
            }
        }

        // check if lastNode is mother vertex
        fill(visited.begin(), visited.end(), false);
        dfs(lastNode, adj, visited);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                return -1;
            }
        }
        return lastNode;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends