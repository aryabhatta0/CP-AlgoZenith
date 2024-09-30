// Not imp
// https://maang.in/problems/Indexed-Set-367?resourceUrl=cs99-cp510-pl3442-rs367
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
/*
    order_of_key (k) : find the index of the element x, if x doesn’t exist it finds the position that the element would have in the set.
    find_by_order(k) : finding the iterator to the xth location.
*/

void solve(){
    int q; cin>>q;

    // accessing set by index ?
    ordered_set s;
    
    string op; int x;
    while(q--){
        cin>>op>>x;

        if(op=="add") s.insert(x);
        else if(op=="remove") {
            if(s.find(x) != s.end())
                s.erase(x);
        }
        else if(op=="find"){
            if(x >= s.size()) cout << "-1\n";
            else {
                cout << *(s.find_by_order(x)) << "\n";
            }
        }
        else {
            cout << s.order_of_key(x) << "\n";
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