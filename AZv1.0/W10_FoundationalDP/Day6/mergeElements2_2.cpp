#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;

// dp[l][r][x]: min cost to merge l...r to x
// ans?
// are all value of x possible? remember x=[0, 50) only coz of modulo
// if x not possible, then we'll take cost as INF
// ans = min(dp[0][n-1][x]) for all x in [0, 50)

// dp[l][r][(AX+BY+Z)%50] = dp[l][mid][A] + dp[mid+1][r][B] + A%50 * B%50   for all mid in [l, r)

int n, x, y, z;
// int a[55];
vector<int> a;
int dp[55][55][55];

bool done[55][55];  // TLE without this
// use of done _/
// kyunki l..r ka calc ho jane ke baad bhi, jo xx ni aa sakta INF hi rahega

int rec(int l, int r, int xx){
    if(l==r) return (a[l]%50 == xx) ? 0 : INF;
    // if(l>r) return INF;

    // if(dp[l][r][xx]!=INF) return dp[l][r][xx];
    if(done[l][r]) return dp[l][r][xx];

    // calculate costs of all possible merging of l...r
    for(int mid=l; mid<r; mid++){
        for(int a=0; a<50; a++){
            for(int b=0; b<50; b++){
                int cost = rec(l, mid, a) + rec(mid+1, r, b) + a*b;
                dp[l][r][(a*x+b*y+z)%50] = min(dp[l][r][(a*x+b*y+z)%50], cost);
            }
        }
    }
    done[l][r] = true;

    // if xx can be made, it must be made by some merging
    return dp[l][r][xx];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y>>z;
    a.resize(n);
    for(int i=0; i<n; i++) cin>>a[i];

    // memset(dp, 100, sizeof(dp));
    // can't initialize INF with memset ??
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            done[i][j] = false;
            for(int k=0; k<50; k++){
                dp[i][j][k] = INF;
            }
        }
    }
    // for(int i=0; i<n; i++) dp[i][i][a[i]%50] = 0;

    int res=INF;
    for(int i=0; i<50; i++)
        res = min(res, rec(0, n-1, i));
    cout << res << "\n";

    // print dp
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         for(int k=0; k<50; k++){
    //             cout << dp[i][j][k] << " ";
    //         } cout << " | ";
    //     } cout << "\n";
    // } cout << "\n";

    return 0;
}