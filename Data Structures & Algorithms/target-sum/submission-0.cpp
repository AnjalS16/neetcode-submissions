class Solution {
public:
    int dfs(int i, int t, vector<int>& nums, vector<unordered_map<int, int>> &dp){
        if(t==0 && i==nums.size()) return 1;
        if(i>=nums.size()) return 0;
        if(dp[i].count(t)) return dp[i][t];
        return dp[i][t] = dfs(i+1, t+nums[i], nums, dp) + dfs(i+1, t-nums[i], nums, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp(nums.size());
        return dfs(0,target, nums, dp);
    }
};
