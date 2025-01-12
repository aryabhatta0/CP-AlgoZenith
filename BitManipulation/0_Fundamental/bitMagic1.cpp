#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int q; 
    cin >> q;

    bitset<60> x;
    while(q--) {
        int t; 
        cin >> t;
        int i;
        bool flag;
        
        if (t == 1) {
            cin >> i;
            cout << x[i] << "\n";
        } 
        else if (t == 2) {
            cin >> i;
            x[i] = 1;
        } 
        else if (t == 3) {
            cin >> i;
            x[i] = 0;
        } 
        else if (t == 4) {
            cin >> i;
            x[i] = 1 - x[i];  // Toggle the bit
        } 
        else if (t == 5) {
            flag = false;
            for(i = 0; i < 60; i++) {
                if(x[i] != 1) {
                    flag = true;
                    break;
                }
            }
            if(flag) 
                cout << "0\n";
            else 
                cout << "1\n";
        } 
        else if (t == 6) {
            flag = false;
            for(i = 0; i < 60; i++) {
                if(x[i] == 1) {
                    flag = true;
                    break;
                }
            }
            if(flag) 
                cout << "1\n";
            else 
                cout << "0\n";
        } 
        else if (t == 7) {
            flag = false;
            for(i = 0; i < 60; i++) {
                if(x[i] == 1) {
                    flag = true;
                    break;
                }
            }
            if(flag) 
                cout << "0\n";
            else 
                cout << "1\n";
        } 
        else if (t == 8) {
            cout << x.count() << "\n";
        } 
        else if (t == 9) {
            cout << x.to_ullong() << "\n";  // Output as ll
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    solve();
    return 0;
}
