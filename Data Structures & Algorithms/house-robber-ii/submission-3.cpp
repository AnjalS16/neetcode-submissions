// class Solution {
// public:
//     int dfs(int i, vector<int>& sub, vector<int>& dp){
//         if(i>=sub.size()) return 0;
//         if(dp[i]!=-1) return dp[i];
//         return dp[i] = max(dfs(i+1, sub, dp), dfs(i+2, sub, dp)+sub[i]);
//     }
//     // int dfs1(int i, vector<int>& rub, vector<int>& dp1){
//     //     if(i>=rub.size()) return 0;
//     //     if(dp1[i]!=-1) return dp1[i];
//     //     return dp1[i] = max(dfs1(i+1, rub, dp1), dfs1(i+2, rub, dp1)+rub[i]);
//     // }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> sub(nums.begin(), nums.end() - 1);
//         vector<int> rub(nums.begin()+1, nums.end());
//         vector<int> dp(n-1, -1);
//         //vector<int> dp1(n-1, -1);
//         //int amt = 0;
//         return max(dfs(0, sub, dp), dfs(0, rub, dp));
//     }
// };

class Solution {
public:
    int dfs(int i, vector<int>& nums, vector<int>& dp) {

        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int skip = dfs(i + 1, nums, dp);
        int take = nums[i] + dfs(i + 2, nums, dp);

        return dp[i] = max(skip, take);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> sub(nums.begin(), nums.end() - 1);
        vector<int> rub(nums.begin() + 1, nums.end());

        vector<int> dp(n - 1, -1);
        vector<int> dp1(n - 1, -1);

        return max(
            dfs(0, sub, dp),
            dfs(0, rub, dp1)
        );
    }
};
