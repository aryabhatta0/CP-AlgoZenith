// https://atcoder.jp/contests/dp/tasks/dp_l

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Taro: (2, 9, 7, 1) → (2, 9, 7)
// greedy won't work, so have to try out all possibilities

// optimal X-Y value given 0th/1st chance first
ll dp[3010][3010][2];
ll back[3010][3010][2];

/** Can solve without the third dimension due to the symmetry of the problem. Look M2. */

int n;
int arr[3010];

ll rec(int l, int r, int p) {
    // base case
    if (l > r) return 0;

    // cache check
    if (dp[l][r][p] != -1) return dp[l][r][p];

    // transition
    ll ans = 0;

    // try out both l & r in both case
    if (p == 0) {
        ll chooseL = arr[l] + rec(l + 1, r, 1 - p);
        ll chooseR = arr[r] + rec(l, r - 1, 1 - p);
        if (chooseL > chooseR) {
            ans = chooseL;
            back[l][r][p] = l;
        } else {
            ans = chooseR;
            back[l][r][p] = r;
        }
    } else {
        ll chooseL = rec(l + 1, r, 1 - p) - arr[l];
        ll chooseR = rec(l, r - 1, 1 - p) - arr[r];
        // 1 will try to minimize X-Y
        if (chooseL < chooseR) {
            ans = chooseL;
            back[l][r][p] = l;
        } else {
            ans = chooseR;
            back[l][r][p] = r;
        }
    }

    // save and return
    return dp[l][r][p] = ans;
}

void generate(int l, int r, int p){
    // base case
    if (l > r) return;

    int ch = back[l][r][p];
    cout << p << " choses ind" << ch << " => " << arr[ch] << " at [" << l << " , " << r << "]\n";
    
    if(ch==l) generate(l+1, r, 1-p);
    else generate(l, r-1, 1-p);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, n - 1, 0) << "\n";

    // generate(0, n-1, 0);
}

// greedy, wrong WA
void solve_greedy() {
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int l=0, r=n-1;
    ll ans=0;
    bool xTurn=true;
    while(l<=r){
        int ch=0;
        if(arr[l]>arr[r]){
            ch = arr[l];
            l++;
        } else {
            ch = arr[r];
            r--;
        }

        if(xTurn) ans += ch;
        else ans -= ch;
        xTurn = !xTurn;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
