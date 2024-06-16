#include <bits/stdc++.h>
using namespace std;

/**
FRAME-LIKE PATTERN :

****
*..*
*..*
****

*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int l, c;
        cin>>l>>c;
        for(int i=1; i<=l; i++){
            for(int j=1; j<=c; j++){
                if(i==1 || i==l || j==1 || j==c) cout << "*";
                else cout << ".";
            }
            cout << endl;
        }
    }
    return 0;
}