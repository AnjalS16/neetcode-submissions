class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(const auto &it : points){
            int x = it[0];
            int y = it[1];
            int dis = (x*x) + (y*y);
            pq.push({dis, {x, y}});
        }
        for(int i = 0; i<k; i++){
            auto [dis, pos] = pq.top();
            auto [a, b] = pos;
            pq.pop();
            res.push_back({a, b});
        }
        return res;
    }
};
