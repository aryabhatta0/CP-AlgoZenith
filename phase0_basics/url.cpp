#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    string url; cin>>url;
    // find first ?
    // replace '=' with ': ' and '&' with '\n'

    // bas print hi toh karna hai
    int flag=0;
    for(auto it: url){
        if(it=='?') {
            flag=1; continue;
        }

        if(flag) {
            if(it=='=') cout << ": ";
            else if(it=='&') cout << "\n";
            else cout << it;
        }
    }
    cout << "\n";

    // for(int i=0; i < url.size(); i++){
    //     if(url[i]=='?') url = url.substr(i+1);
    // }
    // for(int i=0; i < url.size(); i++){
    //     if(url[i]=='=') url[i] = ':';
    //     else if(url[i]=='&') url[i]='\n';

    // }

    // cout << url << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}