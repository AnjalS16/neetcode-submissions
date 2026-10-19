class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0) return 0;
        sort(intervals.begin(), intervals.end());
        int prevend = intervals[0][1];
        int cnt = 0;
        for(int i = 1; i<n; i++){
            if(prevend <= intervals[i][0]){
                prevend = intervals[i][1];
                continue;
            } 
            else {
                prevend = min(prevend, intervals[i][1]);
                cnt++;
            }    
        }
        return cnt;
    }
};
