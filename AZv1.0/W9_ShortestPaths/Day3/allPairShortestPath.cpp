// DOUBT: Samajh nhi aaya

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;

int n;
vector<vector<int>> matrix;

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

    vector<ll> ans;  // final answer array

    // move from backword
    for(int k=n-1; k>=0; k--){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // x[k] - node to be removed
                matrix[i][j] = min(matrix[i][j], matrix[i][x[k]]+matrix[x[k]][j]);
            }
        }

        ll temp = 0;
        for(int i=k; i<n; i++){
            for(int j=k; j<n; j++){
                temp += matrix[x[i]][x[j]];     // 
            }
        }
        ans.push_back(temp);

    }

    reverse(ans.begin(), ans.end());
    for(auto i: ans)
        cout << i << " ";
    cout << endl;
    return 0;
}