#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    const int MOD = 1e9 + 7;
    vector<pair<int, int>> eng(n);
    for (int i = 0; i < n; ++i)
        eng[i] = {efficiency[i], speed[i]};

    sort(eng.rbegin(), eng.rend());

    priority_queue<int, vector<int>, greater<int>> minHeap;
    unsigned long long speedSum = 0, best = 0;

    for (int i = 0; i < n; ++i) {
        int eff = eng[i].first;
        int spd = eng[i].second;

        minHeap.push(spd);
        speedSum += spd;

        if ((int)minHeap.size() > k) {
            speedSum -= minHeap.top();
            minHeap.pop();
        }
        best = max(best, speedSum * eff);
    }
    return best % MOD;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> speed(n), efficiency(n);
    for (int &x : speed) cin >> x;
    for (int &x : efficiency) cin >> x;
    cin >> k;

    cout << maxPerformance(n, speed, efficiency, k) << endl;
    return 0;
}