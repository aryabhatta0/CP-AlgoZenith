// https://maang.in/problems/Queue-using-2-Stacks-AZ101-350?resourceUrl=cs99-cp510-pl3437-rs350
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void swap(stack<int>& s1, stack<int>& s2){
    while(!(s1.empty())){
        int x = s1.top(); s1.pop();
        s2.push(x);
    }
}

void solve(){
    int q; cin>>q;

    stack<int> st1, st2;

    while(q--){
        string str; cin>>str;
        if(str=="push"){
            int x; cin>>x;
            st1.push(x);
        }
        else if(str=="pop"){
            if(!(st2.empty())){
                // pop
                cout << st2.top() << "\n";
                st2.pop();
                continue;
            }

            // swap
            swap(st1, st2);

            // pop
            cout << st2.top() << "\n";
            st2.pop();

            // swap
            // swap(st2, st1);
        }
        else if(str=="front"){
            if(!(st2.empty())){
                // pop
                cout << st2.top() << "\n";
                continue;
            }

            // swap
            swap(st1, st2);

            // front
            cout << st2.top() << "\n";

            // swap
            // swap(st2, st1);
        }
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