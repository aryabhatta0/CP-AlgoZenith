#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        string n;
        cin>>n;

        int sum=0;
        for(int i=0; i<n.length(); i++){
            sum += n[i] - '0';
        }
        cout<<sum<<endl;
    }
    return 0;
}