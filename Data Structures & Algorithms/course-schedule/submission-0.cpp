class Solution {
public:
    bool dfs(int i, unordered_map<int, vector<int>> &adj, unordered_set<int> &vis){
        if(vis.count(i)) return false;
        if(adj[i].empty()) return true;
        vis.insert(i);
        for(int pre : adj[i]){
            if(!dfs(pre, adj, vis)) return false;
        }
        vis.erase(i);
        adj[i].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> vis;
        for(int i = 0; i<numCourses; i++){
            adj[i] = {};
        }
        for(const auto &prereq : prerequisites){
            adj[prereq[0]].push_back(prereq[1]);
        }
        
        for(int i = 0; i<numCourses; i++){
            if(!dfs(i, adj, vis)) return false;
        }

        return true;
    }
};
