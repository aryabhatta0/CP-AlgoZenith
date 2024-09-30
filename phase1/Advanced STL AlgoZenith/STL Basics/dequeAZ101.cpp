#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        deque<int> dq;
        int q;
        cin>>q;
        string str;
        getline(cin, str);
        while(q--){
            getline(cin, str);
            stringstream ss(str);
            string op;
            ss >> op;
            int x;
            if(op=="insertback"){
                ss >> x;
                dq.push_back(x);
            }
            else if(op=="eraseback"){
                if(!dq.empty())
                    dq.pop_back();
            }
            else if(op=="insertfront"){
                ss >> x;
                dq.push_front(x);
            }
            else if(op=="erasefront"){
                if(!dq.empty())
                    dq.pop_front();
            }
            else if(op=="printfront"){
                if(!dq.empty())
                    cout << dq.front() << "\n";
                else
                    cout <<"0\n";
            }
            else if(op=="printback"){
                if(!dq.empty())
                    cout << dq.back() << "\n";
                else
                    cout <<"0\n";
            }
            else if(op=="print"){
                ss >> x;
                if(dq.size()>x)
                    cout << dq[x] << "\n";
                else
                    cout <<"0\n";
            }

            // print dq
            // cout << "dq: ";
            // for(auto i: dq)
            //     cout << i << " ";
            // cout << "\n";
        }
    }
    return 0;
}