#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/CPTTRN1/
// To print a chess like pattern

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int l, c;
        cin >> l >> c;
        bool flag = true;   // true means asterisk
        bool lflag = true;  // row start with asterisk (flag)
        for(int i=0; i<l; i++){
            flag=lflag;
            for(int j=0; j<c; j++){
                if(flag) cout << "*";
                else cout << ".";
                flag = !(flag);
            }
            lflag = !(lflag);
            cout << endl;
        }
    }
    return 0;
}