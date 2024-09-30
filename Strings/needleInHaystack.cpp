#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getKMP(string str){
        int n=str.size();
        vector<int> kmp(n, 0);

        for(int i=1; i<n; i++){
            int j=kmp[i-1];
            while(j>0 && str[i]!=str[j]) j=kmp[j-1];

            if(str[i]==str[j]) j++;
            kmp[i]=j;
        }
        return kmp;
    }

    // more intuitive
    int strStr2(string haystack, string needle) {
        string str = needle + '#' + haystack;
        vector<int> kmp = getKMP(str);

        int m=needle.size();
        for(int i=0; i<kmp.size(); i++){
            if(kmp[i]==m) return i-m-m;
        }
        return -1;
    }


    // advanced
    int strStr(string haystack, string needle){
        int n=haystack.size(), m=needle.size();
        vector<int> lps = getKMP(needle);

        int i=0;    // haystack
        int j=0;    // needle

        while(i<n){
            if(haystack[i]==needle[j]){
                i++; j++;
            } 
            
            if(j==m)   // fpund the needle
                return i-j;
            else if(i<n && haystack[i]!=needle[j]){
                // j doesn't match
                // reduce j to largest k<j that matches with suffix at i
                if(j!=0) j = lps[j-1];
                else i++;
            }
        }
        return -1;
    }
};


// int32_t main() {
//     Solution s;
//     vector<int> nums = {2,1,3,4};
//     int k = 1;
//     cout << s.func() << "\n"; 
//     return 0;
// }