class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, unordered_set<int> &vis){
        if(vis.count(node)) return;
        vis.insert(node);
        for(auto it : adj[node]){
            if(!vis.count(it)) dfs(it, adj, vis);
        }
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> vis;
        int cnt = 0;
        //vis.insert(0);
        for(int i = 0; i<n; i++){
            //for(const auto it : adj[i] ){
                if(!vis.count(i)) {
                    dfs(i, adj, vis);
                    cnt++;
                }
            //}
        }
        return cnt;
    }
};
