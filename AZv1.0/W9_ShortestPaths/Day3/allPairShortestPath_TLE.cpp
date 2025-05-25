#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;

int n;
vector<vector<int>> matrix;
unordered_set<int> nodes;

// O(n^3)
ll floydWarshall(){
    vector<vector<int>> dist = matrix;
    for(auto k: nodes){
        for(auto i: nodes){
            for(auto j: nodes){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    ll sum = 0;
    for(auto i: nodes){
        for(auto j: nodes){
            if(dist[i][j] != INF)
                sum += dist[i][j];
        }
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    matrix.resize(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin>>matrix[i][j];
    }

    vector<int> x(n);
    for(int i=0; i<n; i++) {
        cin>>x[i];
        x[i]--;
    }

    for(int i=0; i<n; i++)
        nodes.insert(i);

    for(auto k: x){
        // cout << "for k =\t" << k << endl;
        cout << floydWarshall() << " ";
        nodes.erase(k);

    }    cout << endl;    

}