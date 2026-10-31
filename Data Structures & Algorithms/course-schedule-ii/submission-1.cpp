class Solution {
public:
    vector<int> res;
    unordered_set<int> vis;
    unordered_set<int> done;
    unordered_map<int, vector<int>> adj;

    bool dfs(int i){
        if(vis.count(i)) return false;
        if(done.count(i)) return true;
        vis.insert(i);
        for(const auto pre : adj[i]){
            if(!dfs(pre)) return false;
        }
        vis.erase(i);
        done.insert(i);
        res.push_back(i);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i = 0; i<numCourses; i++){
            adj[i] = {};
        }
        for(const auto &pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        for(int i = 0; i<numCourses; i++){
            if(!dfs(i)) return {};
        }
        return res;
    }
};
