// Solution 1:

#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> mp;
vector<int> b;

void rec(int l)
{
    if (l == n)
    {
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
        return;
    }
    for (auto &it : mp)
    {
        if (it.second != 0)
        {
            b.push_back(it.first);
            it.second--;
            rec(l + 1);
            it.second++;
            b.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        mp[a]++;
    }
    rec(0);
    return 0;
}

// Solution 2:
/**
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    do
    {
        for (int u : nums)
        {
            cout << u << " ";
        }
        cout << "\n";
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}
*/