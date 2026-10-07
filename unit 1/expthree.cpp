#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int lo = 0, hi = (int)nums.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] > nums[hi])
            lo = mid + 1;          // minimum lies in right half
        else if (nums[mid] < nums[hi])
            hi = mid;              // minimum lies in left half (with mid)
        else
            --hi;                  // equal: safely shrink right boundary
    }
    return nums[lo];
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int &x : nums)
        cin >> x;

    cout << findMin(nums) << endl;
    return 0;
}
