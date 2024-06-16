// https://maang.in/problems/Good-Numbers-23?resourceUrl=cs99-cp510-pl3428-rs23

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int MAX = 1e6+10;
vector<int> likes(MAX, 0);

void solve(){
    int n, k, q; cin>>n>>k>>q;
    // int l[n], r[n];
    int x, y;
    for(int i=0; i<n; i++){
        // cin >> l[i] >> r[i];
        cin>>x>>y;
        likes[x]+=1;
        likes[y+1]-=1;
    }

    // prefix sum
    for(int i=1; i<MAX; i++){
        likes[i] += likes[i-1];
    }

    // good numbers
    for(int i=0; i<MAX; i++){
        if(likes[i]>=k) likes[i]=1;
        else likes[i]=0;
    }

    // queries
    // print how many 1s between l and r

    // prefix sum again?
    for(int i=1; i<MAX; i++){
        likes[i] += likes[i-1];
    }

    // queries
    int l, r;
    for(int i=0; i<q; i++){
        cin>>l>>r;
        int cnt;
        if(l==0) cnt=likes[r];
        else cnt = likes[r]-likes[l-1];
        cout << cnt << "\n";
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}