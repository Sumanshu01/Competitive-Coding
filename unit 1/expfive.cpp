#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    int n = nums.size();
    if (k <= 0 || k > n) return result;
    result.reserve(n - k + 1);
    deque<int> dq;                          // stores indices

    for (int i = 0; i < n; ++i) {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();                 // index outside window

        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();                  // remove smaller elements

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    return result;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int &x : nums)
        cin >> x;
    cin >> k;

    vector<int> res = maxSlidingWindow(nums, k);
    for (int x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
