class Solution {
public:
    int dfs(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i][j+1] != -1) return dp[i][j+1];
        if(j==-1 || nums[j]<nums[i]){
            return dp[i][j+1] = max(1+dfs(i+1, i, nums, dp), dfs(i+1, j, nums, dp));
        }
        else return dp[i][j+1] = dfs(i+1, j, nums, dp);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return dfs(0, -1, nums, dp);
    }
};
