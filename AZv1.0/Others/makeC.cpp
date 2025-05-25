#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int a, int b, int c){
    // ax+by = c
    // y= c-ax / b
    // find a x so that c-ax is div by b
    c%=b;
    a%=b;
    for(int x=0; x<b; x++){
        if((c-a*x) %b==0){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        solve(a, b, c);
    }
    return 0;
}