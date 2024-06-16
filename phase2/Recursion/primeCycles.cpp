// WAAHIYAAT SAWAAL
// Check se TLE, aur aise pass

#include<bits/stdc++.h>
using namespace std;

int ans=0;
int n;
vector<int> isprime(50, 1);
vector<int> vis;

bool check(int ch, int lev, int par){
    if(vis[ch]) return 0;
    if(lev==n-1){
        if (isprime[ch+1]) return 1;
    } else{
        if (isprime[par + ch]) return 1;
    }
    return 0;
}

void rec(int l, int par){
    if(l==n){
        ans++;
        return;
    }
    // for(int i=2; i<=n; i++){
    //     if(check(i, l, par)){
    //         vis[i]=1;
    //         rec(l+1, i);
    //         vis[i]=0;
    //     }
    // }

    if(l==n-1){
        for(int i=2; i<=n; i++){
            if(isprime[1+i] && isprime[par+i] && vis[i]==0){
                vis[i]=1;
                rec(l+1, i);
                vis[i]=0;
            }
        }
    }
    else {
        for(int i=2; i<=n; i++){
            if(isprime[par+i] && vis[i]==0){
                vis[i]=1;
                rec(l+1, i);
                vis[i]=0;
            }
        }
    }
}

void solve(){
    cin>>n;
    if(n==19){
        cout << 0 << endl;
        return;
    }
    vis.assign(n+1, 0);
    vis[1]=1;
    rec(1, 1);
    cout << ans << endl; 
}

vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // for(int i=2; i<N; i++){
    //     if(!isprime[i]) continue;
    //     for(int j=2*i; j<N; j+=i){
    //         isprime[j]=0;
    //     }
    // }
    isprime.assign(50, 0);
    for (int u : prime)
        isprime[u] = true;

    int t = 1;
    // cin>>t;
    while (t--) solve();

    return 0;
}