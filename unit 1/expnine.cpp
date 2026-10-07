#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> subtree;
    vector<long long> ans;

    // First DFS: subtree sizes and answer for root
    void dfs1(int u, int parent) {
        subtree[u] = 1;

        for (int v : adj[u]) {
            if (v == parent) continue;

            dfs1(v, u);
            subtree[u] += subtree[v];
            ans[0] += subtree[v];
        }
    }

    // Second DFS: rerooting
    void dfs2(int u, int parent) {
        for (int v : adj[u]) {
            if (v == parent) continue;

            ans[v] = ans[u] - subtree[v] + (n - subtree[v]);
            dfs2(v, u);
        }
    }

public:
    vector<long long> sumOfDistances(int N,
                                     const vector<vector<int>>& edges) {
        n = N;

        adj.assign(n, {});
        subtree.assign(n, 0);
        ans.assign(n, 0);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return ans;
    }
};

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    for (auto& edge : edges)
        cin >> edge[0] >> edge[1];

    Solution obj;
    vector<long long> result = obj.sumOfDistances(n, edges);

    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i != n - 1)
            cout << " ";
    }

    cout << '\n';

    return 0;
}