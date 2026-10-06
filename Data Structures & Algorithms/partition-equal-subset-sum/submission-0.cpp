class Solution {
public:

    bool dfs(int i, int currsum, int sum, vector<int>& nums, vector<bool>& dp){
        if(i>=nums.size() || currsum>sum) return false;
        if(currsum == sum) return true;
        if(dp[i] == true) return dp[i];
        return dp[i] = dfs(i+1, currsum+nums[i], sum, nums, dp) || dfs(i+1, currsum, sum, nums, dp);
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) return false;
        vector<bool> dp(nums.size(), false);
        return dfs(0, 0, sum/2, nums, dp);
    }
};
