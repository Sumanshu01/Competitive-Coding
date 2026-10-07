#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int longestValidParentheses(const string& s) {
    int maxLen = 0, n = s.size();
    stack<int> st;
    st.push(-1);                        // base index
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty())
                st.push(i);             // new base
            else
                maxLen = max(maxLen, i - st.top());
        }
    }
    return maxLen;
}
int main() {
    string s;
    getline(cin, s);
    cout << longestValidParentheses(s) << endl;
    return 0;
}
