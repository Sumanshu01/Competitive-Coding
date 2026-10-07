#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> maxSubseq(const vector<int>& nums, int len) {
    int drop = (int)nums.size() - len;
    vector<int> st;
    for (int x : nums) {
        while (drop > 0 && !st.empty() && st.back() < x) {
            st.pop_back();
            --drop;
        }
        st.push_back(x);
    }
    st.resize(len);
    return st;
}
vector<int> mergeSeq(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    vector<int>::const_iterator i = a.begin(), j = b.begin();
    while (i != a.end() || j != b.end()) {
        if (lexicographical_compare(j, b.end(), i, a.end()))
            res.push_back(*i++);
        else
            res.push_back(*j++);
    }
    return res;
}
vector<int> maxNumber(vector<int>& n1, vector<int>& n2, int k) {
    int m = n1.size(), n = n2.size();
    vector<int> best;
    for (int i = max(0, k - n); i <= min(k, m); ++i) {
        vector<int> cand = mergeSeq(maxSubseq(n1, i), maxSubseq(n2, k - i));
        if (cand > best) best = cand;
    }
    return best;
}
int main() {
    int m, n, k;
    cin >> m;
    vector<int> nums1(m);
    for (int &x : nums1) cin >> x;
    cin >> n;
    vector<int> nums2(n);
    for (int &x : nums2) cin >> x;
    cin >> k;
    vector<int> res = maxNumber(nums1, nums2, k);
    for (int x : res) cout << x << " ";
    cout << endl;
}
