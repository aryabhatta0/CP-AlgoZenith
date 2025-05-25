//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].  

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        // code here.
        long long int dp[N+1][sum+1];
        for(int i = 0; i <= N; i++) dp[i][0] = 1;
        for(int i = 1; i <= sum; i++) dp[0][i] = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= sum; j++){
                if(coins[i-1] <= j) dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends