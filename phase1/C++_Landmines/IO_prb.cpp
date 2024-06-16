// https://maang.in/problems/IO-Problem-AZ101-338?resourceUrl=cs99-cp510-pl3421-rs338

#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

/** HINT: Process the numbers in the string to get the floating-point */

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string m;
        cin>>n>>m;
        
        // y & z
        int dot = m.find('.');
        // cout << dot << endl;
        int y = stoi(m.substr(0, dot));
        int z = stoi(m.substr(dot+1, m.length() - dot - 1));
        // cout << y << " " << z << endl;
        
            
        cout << (z+n) << "." << (y+n) << endl;
    }
}