// https://maang.in/problems/Odd-One-Out-AZ101-319?resourceUrl=cs99-cp510-pl3421-rs319

/** CONCEPT: Xor of a number with itself is 0. */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        // int a[n];   // no need to even store array
        int y;
        int xor_=0;
        for(int i=0; i<n; i++){
            cin>>y;
            xor_ ^= y;
        }
        cout << xor_ << endl;        
    }
}