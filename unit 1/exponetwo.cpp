#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    if (n < 4) return result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
        if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
            if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

            int left = j + 1, right = n - 1;
            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    ++left; --right;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                }
                else if (sum < target) ++left;
                else --right;
            }
        }
    }
    return result;
}

int main() {
    int n, target;
    cin >> n;

    vector<int> nums(n);
    for (int &x : nums)
        cin >> x;
    cin >> target;

    vector<vector<int>> result = fourSum(nums, target);

    for (auto &quad : result) {
        for (int x : quad)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
