#include <bits/stdc++.h>
using namespace std;

/** Intuition:
- Finding #CC
- Finding sizes of merged sets (CC)
- Maintaining sets / Merging something
   
    => Think of Disjoint Set! (Union Find)
 */

/* UnionFind is goated
 * Idea: Maintaining sets => Union Find
 * We'll be using tree for the task
 * 
 * Each set will have a root/representative node
 * Path Compression: Connect each node of tree directly to its root after every find call
 * 
 * Rank Compression: smaller-to-larger trick
 * by_size is preferred, since size is req in most of the questions
 * rank[i] = rank (height/size) of set containing node i
 * 
 * Both path and rank compression makes this almost of <=O(6) in CP contest
*/

struct UnionFind {
    int n, numComponents;
    // int *parent, *rank;
    vector<int> parent, rank;

    UnionFind() {}
    UnionFind(int a){
        n = numComponents = a;
        // parent = new int[n+1]; rank = new int[n+1];
        parent.resize(n+1); rank.resize(n+1);

        for(int i=1; i<=n; i++){
            parent[i] = i;
            rank[i]=1;          // rank by size
            // rank[i]=0;          // rank by height
        }
    }

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);     // path-compression
    }
    bool same(int x, int y){
        return find(x)==find(y);
    }

    void merge(int x, int y){
        int xroot = find(x), yroot = find(y);
        if(xroot==yroot) return;

        // smaller-to-larger trick
        if(rank[xroot] >= rank[yroot]){
            parent[yroot] = xroot;
            rank[xroot] += rank[yroot];        // rank-compression by size

            // rank-compression by height
            // if(rank[xroot]==rank[yroot]) rank[xroot]++;
        } else {
            parent[xroot] = yroot;
            rank[yroot] += rank[xroot];        // rank-compression by size
            // no update in rank here for rank-compression by height
        }
        // succesfully merged
        numComponents--;
    }

    void reset(){ 
        numComponents=n;
        for(int i=1; i<=n; i++){ parent[i] = i; rank[i]=1; }
    }
    int getNumSets(){ return numComponents; }
    void print(){ for(int i=1; i<=n; i++) cout << i << " -> " << parent[i] << "\n"; }
};



int main() {
    int size = 10;
    UnionFind uf(size);

    uf.merge(1, 2);
    uf.merge(3, 4);
    uf.merge(2, 4);

    cout << "1 and 3 are same: " << uf.same(1,3) << "\n";

    // connected components
    cout << "Number of #CC: " << uf.getNumSets() << endl;

    uf.print();
    return 0;
}
