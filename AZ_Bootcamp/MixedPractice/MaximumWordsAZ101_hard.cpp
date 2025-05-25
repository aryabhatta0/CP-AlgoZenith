// https://maang.in/problems/Maximum-Area-AZ101-374?resourceUrl=cs117-cp540-pl3641-rs374&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/** Intuition:
 * Area nikalna hai. Kuch toh height and width store karenge!

 * At one point, you're either making a horizontol cut or vertical. 
 * That's you're either reducing height or width of last new max area rectangle.
 * Hori Cut: 
    Reducing height by how much? Depends upon nearest past hori cuts on both sides.
    Won't affect width.
 * Similarly for Verti Cut!

 * Use multisets for height/width. think why?
 */

void solve(){
    int h, w, n; cin>>h>>w>>n;

    multiset<int> height, width;
    height.insert(h); width.insert(w);

    set<int> horiCut, vertiCut;
    horiCut.insert(0); horiCut.insert(h);
    vertiCut.insert(0); vertiCut.insert(w);

    while(n--) {
        char ch; int cut;
        cin>>ch>>cut;
        if(ch=='H') {
            // find nearest hori already existing cuts
            auto it = horiCut.lower_bound(cut);
            int upp = *it;
            it--;
            int low = *it;

            height.erase(height.find(upp - low));
            height.insert(upp - cut);
            height.insert(cut - low);

            ll area = 1LL * (*(height.rbegin())) * (*(width.rbegin()));
            cout << area << "\n";

            horiCut.insert(cut);
        } else if(ch=='V') {
            // find nearest verti already existing cuts
            auto it = vertiCut.lower_bound(cut);
            int right = *it;
            it--;
            int left = *it;

            width.erase(width.find(right - left));
            width.insert(right - cut);
            width.insert(cut - left);

            ll area = 1LL * (*(height.rbegin())) * (*(width.rbegin()));
            cout << area << "\n";

            vertiCut.insert(cut);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}