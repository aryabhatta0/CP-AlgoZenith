// https://maang.in/problems/Tree-Diameter-II-428?resourceUrl=cs99-cp522-pl3603-rs428
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// cnt number of diameters
// find centre and then think separately for both 1 & 2 centres using PnC

int n;
vector<vector<int>> adj;
vector<int> depth;
vector<int> parent;

int dia;
int cnt=0;  // cnt of no. of vals at depth dia/2 -1

// depth[0]=-1 _/
// always set the depth of virtual node
void dfs(int node, int par){
    depth[node] = depth[par]+1;     
    parent[node] = par;

    if(depth[node]== dia/2 ) cnt++;

    for(int v: adj[node]){
        if(v!=par){
            dfs(v, node);
        }
    }
}

void solve(){
    cin>>n;
    // always check such edge cases
    if(n==1) {
        cout << "1\n";          // how??
        return;
    } 
    // else if(n==2){
    //     cout << "1\n";
    //     return;
    // }

    adj.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    depth.resize(n+1);
    depth[0]=-1;    // alway set dep of virtual parent :)
    parent.resize(n+1);
    dfs(1, 0);

    int start=1;
    for(int i=1; i<=n; i++){
        if(depth[i] > depth[start])
            start = i;
    }

    dfs(start, 0);
    int end=1;
    for(int i=1; i<=n; i++){
        if(depth[i] > depth[end])
            end = i;
    }

    // cout << "st: " << start << " end: " << end << "\n";
    dia = depth[end];
    // cout << "dia: " << dia << "\n";

    auto it=end;
    while(it != start){
        if(depth[it]==dia/2 + 1)    // it is node just before last dia from end
            break;
        it = parent[it];
    }

    // single centre
    if(dia %2 ==0){
        int c1 = parent[it];

        // cnt of leaves with dep dia/2 in each subtree in c1's neighbour
        vector<int> count;    
        depth[c1]=0;
        for(int v: adj[c1]){
            cnt=0;
            dfs(v, c1);     // it'll only explore the subtree at v
            count.push_back(cnt);
        }
        int sz = count.size();

        // Find all sum of all pair product of count

        // prefix sum
        // vector<ll> prefix(sz);
        // prefix[0] = count[0];
        // for (int i = 1; i < sz; i++) {
        //     prefix[i] = count[i] + prefix[i - 1];
        // }

        // ll ans=0;
        // for(int i=0; i<sz; i++){
        //     ans += 1LL* count[i] * (prefix[sz-1]-prefix[i]);
        // }
        // cout << ans << "\n";

        // without prefix sum
        ll sum=0;
        for (int i = 1; i < sz; i++) {
            sum+= count[i];
        }

        ll ans=0;
        for (int i = 0; i < sz-1; i++) {
            ans += 1LL * count[i] * sum;
            sum -= count[i+1];
        }
        cout << ans << "\n";

        /* best way to find all pair sum:
        int ans = 0;
        int sum = 0;
        for(auto x : count) {
            ans += sum*x;
            sum += x;
        }
        cout<<ans<<endl;
        */
    } 
    // two centre
    else {    
        int c1=it;
        int c2=parent[it];
        // cout << "centres: " << c1 << " " << c2 << "\n";

        // no. of nodes with dep dia/2 -1 on c1 subtree
        cnt=0;
        depth[c2]=-1;
        dfs(c1, c2);
        int m=cnt;

        // no. of nodes with dep dia/2 on c2 subtree
        cnt=0;
        depth[c1]=-1;
        dfs(c2, c1);
        int n=cnt;

        ll ans = 1LL* m * n;
        cout << ans << "\n";
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}