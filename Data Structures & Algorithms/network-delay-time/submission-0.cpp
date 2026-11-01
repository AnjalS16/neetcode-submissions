class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(const auto &edge : times){
            int src = edge[0];
            int next = edge[1];
            int t = edge[2];
            adj[src].push_back({next, t});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if(d>dist[node]) continue;
            //if(node==n) return d;
            for(auto [next, t] : adj[node]){
                int newtime = d + t;
                if(newtime < dist[next]){
                    dist[next] = newtime;
                    pq.push({newtime, next});
                }
            }
        }
        int ans=0;
        for(int i = 1; i<=n; i++){
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
