// Std Floyd Warshall Problem

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;

int n, m, q;
vector<vector<ll>> dist;

void printer(){
    cout << "dist:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

void floydWarshall(){
    for(int k=1; k<=n; k++){   // via k node
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    dist.resize(n+1, vector<ll>(n+1, INF));
    for(int i=1; i<=n; i++) dist[i][i]=0;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = min(dist[a][b], (ll)c);
    }

    // printer();
    floydWarshall();
    // printer();

    int u, v;
    while(q--){
        cin>>u>>v;
        cout << (dist[u][v]==INF ? -1 : dist[u][v]) << "\n";
    }
}