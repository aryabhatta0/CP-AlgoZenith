#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        map<string, int> mp;
        int q;
        cin>>q;
        string str;
        getline(cin, str);
        while(q--){
            getline(cin, str);
            stringstream ss(str);
            string op;
            ss >> op;
            string x;
            int y;
            if(op=="add"){
                ss >> x >> y;
                mp[x]=y;  // can also use .insert() to insert or update
            } else if(op=="erase"){
                ss >> x;
                mp.erase(x);
            } else if(op=="print"){
                ss >> x;
                if(mp.find(x)!=mp.end())
                	cout << mp[x] << "\n";
                else
                    cout << "0\n";
            }
            
        }
    }
    return 0;
}