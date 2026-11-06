class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for(int pass = 0; pass<=k; pass++){
            vector<int> nextprices = prices;
            for(const auto& flight : flights){
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];

                if(prices[from]==INT_MAX) continue;
                nextprices[to] = min(nextprices[to], prices[from]+cost);
            }
            prices.swap(nextprices);
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
