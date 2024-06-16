// https://maang.in/problems/Can-You-Make-C-66?resourceUrl=cs99-cp510-pl3424-rs66
/** QUES:
Ax + By = C, Given three positive integers A, B and C.
You have to determine whether there exists at least one solution 
for some integers value of x and y where x, y may be negative or non-negative integers.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/** CONCEPT: Bezout's identity
 *  The GCD of two numbers a and b can be expressed as ax+by for some x and y.
 * 
 * ax + by = gcd(a,b)  will have a soln
 * ax + by = n * gcd(a,b) will also have a soln
*/

void solve(int a, int b, int c){
    // ax+by = c
    // ax+by / c = 1
    // g(fx+hy)/c = 1
    // if g%c == 0
    
    // ASSUMPTION:
    // ax+by=c will always have an int soln if nothig could be taken out from lhs
    // i.e, if gcd(a, b)==1
    // why??
    
    int g = __gcd(a,b);
    if(c%g==0)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

// TLE, but good idea
void solve_TLE(int a, int b, int c){
    // ax+by = c
    // y= c-ax / b
    // find one x so that c-ax is div by b
    // think in modular realm! when can b divide something.
    
    if(b>a){
        int temp=b; b=a; a=temp;  // swap a, b
    }

    c%=b; a%=b;
    for(int x=0; x<b; x++){
        if((c-(a*x)%b) %b==0){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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