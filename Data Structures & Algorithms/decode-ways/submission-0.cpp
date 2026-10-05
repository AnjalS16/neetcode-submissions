class Solution {
public:
    
    int dfs(int i, string& s, vector<int>& dp){
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i] != -1) return dp[i];
        if (i + 1 >= s.size() || s.substr(i, 2) > "26")
            return dp[i] = dfs(i + 1, s, dp);
        return dp[i] = dfs(i+1, s, dp) + dfs(i+2, s, dp);
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return dfs(0, s, dp);
    }
};
