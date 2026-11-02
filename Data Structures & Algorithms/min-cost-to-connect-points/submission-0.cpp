class Solution {
public:
    int find(int node, vector<int>& parent) {
        if (parent[node] != node) {
            parent[node] = find(parent[node], parent);
        }
        return parent[node];
    }

    bool unite(int u, int v, vector<int>& parent,
               vector<int>& sz) {
        int rootU = find(u, parent);
        int rootV = find(v, parent);

        if (rootU == rootV) return false;

        if (sz[rootU] < sz[rootV]) swap(rootU, rootV);

        parent[rootV] = rootU;
        sz[rootU] += sz[rootV];

        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dis = abs(points[i][0] - points[j][0])
                        + abs(points[i][1] - points[j][1]);

                edges.push_back({dis, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(n), sz(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int totalCost = 0;
        int edgesUsed = 0;

        for (auto [weight, u, v] : edges) {
            if (unite(u, v, parent, sz)) {
                totalCost += weight;
                edgesUsed++;

                if (edgesUsed == n - 1) break;
            }
        }

        return totalCost;
    }
};