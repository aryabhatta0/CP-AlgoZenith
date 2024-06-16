#include <bits/stdc++.h>
using namespace std;

// Best for multiple types of parentheses !

int main()
{
    map<char, int> mp;
    mp['('] = +1;
    mp['['] = +2;
    mp['{'] = +3;
    mp[')'] = -1;
    mp[']'] = -2;
    mp['}'] = -3;
    mp['<'] = +4;
    mp['>'] = -4;

    string s;
    cin >> s;
    stack<int> st;
    int is_balanced = 1;

    for (auto v : s)
    {
        int val = mp[v];
        if (val > 0)
        {
            // open bracket type
            st.push(val);
        }
        else
        {
            if (!st.empty() && st.top() + val == 0)
            {
                st.pop();
            }
            else
            {
                is_balanced = 0;
                break;
            }
        }
    }

    if (!st.empty())
        is_balanced = 0;

    if (is_balanced)
        cout << "Is Balanced\n";
    else
        cout << "Not balanced\n";
}

