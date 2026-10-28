class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &dp, vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k = i; k<=j; k++){
            int coins = dfs(i, k-1, dp, nums) + dfs(k+1, j, dp, nums) + nums[i-1]*nums[k]*nums[j+1];
            ans = max(ans, coins);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2, -1));
        vector<int> balloons = {1};
        for (int num : nums) balloons.push_back(num);
        balloons.push_back(1);
        return dfs(1, nums.size(), dp, balloons);
    }
};
