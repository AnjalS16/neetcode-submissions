class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        // set<pair<int, int>> st;
        // for(int i = 0; i<n-1; i++){
        //     vector<int> temp;
        //     if(intervals[i][0] <= intervals[i+1][0]){
        //         //temp.push_back(intervals[i][0]);
        //         if((intervals[i][1] >= intervals[i+1][0]) || (intervals[i][1] >= intervals[i+1][0])){
        //             temp.push_back(intervals[i][0]);
        //             temp.push_back(max(intervals[i][1], intervals[i+1][1]));
        //         }
        //         // else{
        //         //     temp.push_back(intervals[i][1]);
        //         // }                        
        //         //if(intervals[i][1] < intervals[i+1][0]) continue;
        //     }
        //     if(!temp.empty()) st.insert({temp[0], temp[1]});
        //     if(i==n-2 && temp.empty()){
        //         st.insert({intervals[n-1][0], intervals[n-1][1]});
        //     }
        // }
        // for(const auto& [a, b] : st) res.push_back({a, b});

        for(const auto &interval : intervals){
            if(res.empty() || interval[0]>res.back()[1]) res.push_back(interval);
            else res.back()[1] = max(res.back()[1], interval[1]);
        }

        return res;
    }
};
