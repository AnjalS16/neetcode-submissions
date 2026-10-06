class Solution {
public:
    bool dfs(int i, vector<int> &dp, string&s, vector<string>& wordDict){
        if(i==s.size()) return true;
        if(dp[i] != -1) return dp[i];
        for(string word : wordDict){
            if(i+word.size() <= s.size() && s.substr(i, word.size())==word){
                if(dfs(i+word.size(), dp, s, wordDict)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        vector<int> dp(s.size(), -1);
        return dfs(0, dp, s, wordDict);
    }
};
