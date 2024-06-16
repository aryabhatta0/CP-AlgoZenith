#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n; 
// vector<int> currAns;
int par;
int cnt=0;

// bool isPrime(int n){
//     if (n <= 1) return 0;
//     for (int i = 2; i * i <= n; i++) {  
//         if (n % i == 0) return 0;
//     }
//     return 1;
// }
const int N = 50;
bool isPrime[N];
// vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool marked[N];     // to not use find

bool check(int ch, int lev, int par){
    if(marked[ch]) return 0;
    if(lev==n-1){
        if (isPrime[ch+1]) return 1;
    } else{
        if (isPrime[par + ch]) return 1;
    }
    return 0;
}

void rec(int lev, int par){
    // base case
    if(lev==n){
        cnt++;
        // cout << "Sol: ";
        // for(auto it: currAns) cout << it << " "; cout<<"\n";
        return;
    }

    // choices
    for(int i=2; i<=n; i++){    // 1 already taken
        if(check(i, lev, par)){
            // currAns.push_back(i);
            marked[i] = true;
            rec(lev+1, i);
            // currAns.pop_back();
            marked[i] = false;
        }
    }
}

void solve(){
    cin>>n;
    cnt=0;

    // isPrime
    for (int u : prime)
    {
        isPrime[u] = true;
    }

    // currAns.push_back(1);   // since we have to find the cycle
    marked[1] = true;
    rec(1, 1);
    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}