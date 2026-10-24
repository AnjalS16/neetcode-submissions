class Solution {
public:
    int dfs(int i, int canBuy, vector<int>& prices,
            vector<vector<int>>& dp) {
        if (i >= prices.size()) return 0;

        if (dp[i][canBuy] != -1) return dp[i][canBuy];

        if (canBuy) {
            int buy = -prices[i] + dfs(i + 1, 0, prices, dp);
            int skip = dfs(i + 1, 1, prices, dp);

            return dp[i][canBuy] = max(buy, skip);
        }

        int sell = prices[i] + dfs(i + 2, 1, prices, dp);
        int hold = dfs(i + 1, 0, prices, dp);

        return dp[i][canBuy] = max(sell, hold);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(0, 1, prices, dp);
    }
};