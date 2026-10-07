#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct DSU {
    vector<int> parent, rnk;
    DSU(int n) : parent(n + 1), rnk(n + 1, 0) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (rnk[u] < rnk[v]) swap(u, v);
        parent[v] = u;
        if (rnk[u] == rnk[v]) ++rnk[u];
        return true;
    }
};
vector<int> findRedundantDirectedConnection(vector<vector<int> >& edges) {
    int n = edges.size();
    vector<int> parent(n + 1, 0), cand1, cand2;
    for (size_t i = 0; i < edges.size(); ++i) {      // find in-degree 2
        int u = edges[i][0], v = edges[i][1];
        if (parent[v] == 0) parent[v] = u;
        else {
            cand1 = vector<int>{parent[v], v};
            cand2 = edges[i];
        }
    }
    DSU dsu(n);                                      // skip cand2 if present
    for (size_t i = 0; i < edges.size(); ++i) {
        if (edges[i] == cand2) continue;
        if (!dsu.unite(edges[i][0], edges[i][1]))
            return cand1.empty() ? edges[i] : cand1;
    }
    return cand2;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int> > edges(n, vector<int>(2));
    for (int i = 0; i < n; ++i)
        cin >> edges[i][0] >> edges[i][1];
    vector<int> res = findRedundantDirectedConnection(edges);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    return 0;
}
