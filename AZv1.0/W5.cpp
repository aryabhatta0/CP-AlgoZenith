// https://www.learning.algozenith.com/problems/Count-Unique-Char-in-Substrings-61
// Count Unique Char in Substrings
// Difficulty: Medium

// Lesson of the day: Think of iterating over all A-Z chars for similar char/string sum problems

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** Official Soln | Logic: 
 * for each char indices, find its nearest left and right occurence
 * for subarray with just one char,
 *  - left end can be anywhere b/w left and curr occurence
 *  - right end can be anywhere b/w curr and right occurence 
 * therefore multiply the len differences to get all possible subarrays
 * = (curr-left+1)*(right-curr+1)
*/

// returns no. of subarrays having just one ch
ll contri(char ch, string s, int n){
    int tail=0, head=-1;
    bool pres=false;    // char ch is present in subarray
    ll presInd=-1;

    ll res=0;
    while(tail<n){
        while(head+1<n && ((s[head+1]==ch && !pres) || (s[head+1]!=ch))){
            head++;
            if(s[head]==ch){
                pres=true;
                presInd=head;
            }
        }
        if(pres){
        	// res += (head-tail+1);
        	res += (head-presInd+1);    
            // presInd coz for c in acb => we won't be taking all subarr for ac (only ac, not a)
            // cout << "\nsubarray b/w " << tail << " and " << head << " => " << s.substr(tail, head-tail+1) << "\n";
        }
        // else
        //     break;
        
        if(s[tail]==ch){
            pres=false;
            presInd=-1;
        }
        tail++;
        if(tail>head)
            head=tail-1;
    }
    return res;
}

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    
    ll score=0;
    for(char c='a'; c<='z'; c++){
        // contr of c in score
        // cout << c << " => ";
        ll temp = contri(c, s, n);
        // cout << temp << "\n";
        score+= temp; 
    }
    cout<<score<<"\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}