#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    stack<int> s;   // stores indices of histogram

    // stack is always maintained in increasing order of heights corresponding to the indices

    ll max=0;
    for(int i=0; i<n; i++){
        if(s.empty() || a[s.top()]<=a[i]) s.push(i);
        else{
            while(!s.empty() && a[s.top()]>a[i]){
                int top = s.top();
                s.pop();
                ll area = 1LL*a[top]*(s.empty()?i:i-s.top()-1);
                // int area = a[top]*(s.empty()?i:1);   // 2 2 10 10 5
                // cout << "poping " << top << " area=" << area << "\n";
                if(area>max) max=area;
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        int top = s.top();
        s.pop();
        ll area = 1LL*a[top]*(s.empty()?n:n-s.top()-1);
        if(area>max) max=area;
    }
    cout << max << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}