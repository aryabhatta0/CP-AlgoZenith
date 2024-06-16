#include <bits/stdc++.h>
using namespace std;

// Grid-like pattern

string getBoundary(int c){
    string str = "*";
    for(int i=0; i<c; i++){
        str += "***";
    }
    return str;
}

void solve(){
    int l, c;
    cin>>l>>c;

    string boundary = getBoundary(c);
    cout << boundary << endl;
    for(int i=0; i<l; i++){     // l rows

        string str = "";
        str+="*";
        for(int j=0; j<c; j++) {    // c squares
            str += "..*";
        }

        cout << str << endl << str << endl;     // sq of side 2 (4 dots)
        cout << boundary << endl;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
