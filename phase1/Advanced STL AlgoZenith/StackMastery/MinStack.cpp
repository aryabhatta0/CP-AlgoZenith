// https://maang.in/problems/Min-Stack-459?resourceUrl=cs117-cp540-pl3642-rs459&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q: Implement a stack that also supports getMin()
#include<bits/stdc++.h>
using namespace std;

// Key Idea: Use two stacks - think for cases agla element bada aaya ya chhota
// Put smaller elements in minStack
// Chhote element ke baad bada aaya, fadak ni padta - wo kabhi bhi min nahi hone wala hai
// Think!!!
class MinStack {
private:
    stack<int> st;
    stack<int> minSt;
public:

    MinStack() {}

    void push(int x) {
        // mst.insert(x);
        st.push(x);
        if(minSt.empty() || x <= minSt.top()) minSt.push(x);
    }

    void pop() {
        if(st.empty()) return;
        if(st.top()==minSt.top()) minSt.pop();
        st.pop();
    }

    int top() {
        return (st.empty() ? -1 : st.top());
    }

    int getMin() {
        return (minSt.empty() ? -1 : minSt.top());
    }
};


///////////////////// Clever, Interesting Approach ///////////////
// Thought kaise ayega bhai???????
/*
- minEle is being stored
- aage minEle se bada value aa raha, ghanta farak ni padta, keep doing ur thing
- chhota value aaya, encode that using prev minEle, update minEle
- top minEle se chota hai, matlab yeh encoded minEle hai

y = 2min - x    =>   x = 2min - y
(y and min store kar rahe hai, x is prev min) Uff
*/
class MinStack {
private:
    stack<int> st;
    int minEle; 
public:
    MinStack() {}
    void push(int x) {
        if(st.empty()) {
            st.push(x);
            minEle = x;
        }
        else if(x >= minEle) {
            st.push(x);
        }
        // If the new element is less than minEle, push the encoded value
        else {
            st.push(2*x - minEle);
            minEle = x;
        }
    }

    void pop() {
        if(st.empty()) return;

        int top = st.top();
        st.pop();

        // If the popped value is greater than or equal to minEle, do nothing
        if(top >= minEle) {
            // The current minEle remains unchanged
        }
        // If the popped value is less than minEle, it was an encoded value
        else {
            // Recover the previous minEle before this element was pushed
            minEle = 2*minEle - top;
        }
    }

    int top() {
        if(st.empty()) return -1;

        int top = st.top();
        // If the top is less than minEle, it means it's encoded, so return minEle
        if(top < minEle) {
            return minEle;
        }
        return top;
    }

    int getMin() {
        if(st.empty()) return -1;
        return minEle;
    }
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q; cin >> q;

    MinStack s;

    while(q--) {
        string op;
        cin >> op;

        if(op == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        else if(op == "pop") {
            s.pop();
        }
        else if(op == "top") {
            cout << s.top() << "\n";
        }
        else if(op == "getMin") {
            cout << s.getMin() << "\n";
        }
    }

    return 0;
}
