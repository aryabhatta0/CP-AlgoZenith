// Iterative editorial solution

#include <bits/stdc++.h>
using namespace std;

int dp[3001][3001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();

	for(int i = 0 ; i <= n; ++i) {
		for(int j = 0; j <= m; ++j)  {
			if(!i || !j) dp[i][j] = 0;
			else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

    // print dp
    cout << "dp: \n";
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++) cout << dp[i][j] << " ";
        cout << "\n";
    } cout << "\n";

	string ret = "";

	while(n && m) {
		if(s[n - 1] == t[m - 1]) {
			ret += s[n - 1];
			n--;
			m--;
		}
		else if(dp[n - 1][m] > dp[n][m - 1]) n--;
		else m--;
    }

    reverse(ret.begin(), ret.end());

    cout << ret << endl;
}