// https://maang.in/problems/Molecular-Formula-460?resourceUrl=cs117-cp540-pl3642-rs460&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

string evaluate(string formula) {
    // you could even store {atom, cnt} in stack, not just chars uff
    stack < pair < string, int > > s;

    for(int i = 0; i < (int)formula.length(); i++) {
        if(formula[i] == '(') {
            s.push({"(", -1});
        }
        // eval the expression under ( ) and put back in stack
        else if(formula[i] == ')') {
            int multiplier = 0;
            while(i + 1 < (int)formula.length() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                multiplier *= 10;
                multiplier += formula[i + 1] - '0';
                i++;
            }
            if(!multiplier) multiplier = 1;

            stack < pair < string, int > > temp;

            while(!s.empty()) {
                auto it = s.top();
                s.pop();
                if(it.first == "(") break;
                temp.push({it.first, it.second * multiplier});
            }

            while(!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
        }
        // parse the atom name and its num
        else if(formula[i] >= 'A' && formula[i] <= 'Z') {
            string atom = "";
            atom += formula[i];
            while(i + 1 < (int)formula.length() && formula[i + 1] >= 'a' && formula[i + 1] <= 'z') {
                atom += formula[i + 1];
                i++;
            }

            int cnt = 0;
            while(i + 1 < (int)formula.length() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                cnt *= 10;
                cnt += formula[i + 1] - '0';
                i++;
            }

            if(!cnt) cnt = 1;

            s.push({atom, cnt});
        }
    }

    // store back final freq of atoms in map
    map < string, int > M;    // {atom, freq}

    while(!s.empty()) {
        M[s.top().first] += s.top().second;
        s.pop();
    }

    // compute ans
    string ans = "";
    for(auto it : M) {
        ans += it.first;
        if(it.second > 1) ans += to_string(it.second);
    }

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str; cin>>str;
    cout << evaluate(str) << "\n";
    return 0;
}