#include <bits/stdc++.h>
using namespace std;

/**
 * Grid-like pattern.
 * IDEA: Break into rows. Generate row, print repeatedly.
*/


string getBoundary(int c, int w){
    string str = "*";

    string rect="";  // individual rect
    for(int i=0; i<w; i++) rect += "*";
    rect += "*";

    for(int i=0; i<c; i++){
        str += rect;
    }
    return str;
}

string getRows(int c, int w) {
    string row = "*";

    string rect="";  // individual rect
    for(int i=0; i<w; i++) rect += ".";
    rect += "*";

    for(int i=0; i<c; i++){     // c rectangles
        row += rect;
    }
    return row;
}


void solve(){
    int l, c, h, w;
    cin>>l>>c>>h>>w;

    string bndry = getBoundary(c, w);
    cout << bndry << "\n";

    // generate rows
    string row = getRows(c, w);
    ///

    for(int i=0; i<l; i++){     // l rows overall
        for(int k=0; k<h; k++){ // k rows in a row  (height of rect)
            cout << row << "\n";
        }
        cout << bndry << "\n";
    }
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}