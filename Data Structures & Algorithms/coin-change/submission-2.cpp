class Solution {
public:
    
    int dfs(int amount, vector<int>& coins, vector<int>& dp){
        if(amount==0) return 0;
        if(dp[amount] != -1) return dp[amount];
        int res = INT_MAX;
        for(int coin : coins){
            if(amount-coin >= 0){
                int result = dfs(amount-coin, coins, dp);
                if(result!=INT_MAX){
                    res = min(res, 1+result);
                }
            }
        }
        dp[amount] = res;
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount+1, -1);
        int mincoins = dfs(amount, coins, dp);
        return mincoins == INT_MAX ? -1 : mincoins;
    }
};
