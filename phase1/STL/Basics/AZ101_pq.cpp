#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        priority_queue<int> pq;
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
            if(op=="add"){
                ss >> x;
                pq.push(x);
            } else if(op=="remove"){
                if(!pq.empty())
                	pq.pop();
            } 
            else if(op=="print"){
                if(!pq.empty())
                    cout << pq.top() << "\n";
                else
                    cout << "0\n";
            }
            
        }
    }
    return 0;
}