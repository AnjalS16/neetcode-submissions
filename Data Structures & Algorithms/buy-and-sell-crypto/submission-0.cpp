class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        //vector<int> dp(n);
        int l = 0;
        int r = 0;
        while(r<n){
            if(prices[r] > prices[l]){
                int pro = prices[r] - prices[l];
                profit = max(pro, profit);
            }
            else l = r;
            r++;
        }
        return profit;
    }
};
