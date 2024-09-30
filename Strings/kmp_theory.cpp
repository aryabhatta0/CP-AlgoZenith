#include <bits/stdc++.h>
using namespace std;

/** CONCEPT:
 * LongestPrefixSuffix: For each ind, we gotta find longest proper suffix that's also a prefix      s[0...ind]
 * 
 * #1 kmp[i] <= kmp[i-1]+1
 * 
 * we find longest j that follows kmp property and the next char matches with s[i] i.e, s[i]==s[j]
 * , and update kmp[i]=j+1;
 * How to find j? 
 * #2 Obsv. j=kmp[i-1];
 * 
 * TIME COMPLEXITY: O(n)
 * Although there is a nested loop, each character of the string s is processed at most twice: once when it matches and once when it does not match and causes a jump.
 * Therefore, the T.C proportional to the length of the string, leading to a linear time complexity.
 */

// https://cp-algorithms.com/string/prefix-function.html
vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
            
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    
    return pi;
}


// explaination
vector<int> kmpFunction(string str){
    int n=str.size();
    vector<int> kmp(n, 0);
    kmp[0]=0;
    
    for(int i=1; i<n; i++){
        int j=kmp[i-1];     // s[0...j-1] == s[...i-1]
        // j is the ind of char to check with str[i]
        
        
        while(j>0 && str[i]!=str[j])    // find a k<j so that kmp prop still holds i.e, s[0..k] == s[..i-1]
            j = kmp[j-1];       // kmp stores the length, so that's also the iter to next elem
        
        if(str[i]==str[j]) j++;     // len would be ind+1. separate check for j=0.
        kmp[i]=j;
    }
    
    return kmp;
}

// another approach - GPT
vector<int> computeLPSArray(const string &pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);

    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                // This is tricky. Consider the example "AAACAAAA" and i = 7.
                length = lps[length - 1];
                // We do not increment i here
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main()
{
    // string str = "abcabcd";
    string str = "aabaaab";
    vector<int> kmp;
    
    kmp = prefix_function(str);
    kmp = kmpFunction(str);
    
    cout << "kmp arr: ";
    for(auto it: kmp) cout << it << " ";
    cout << "\n";

    return 0;
}