class Solution {
public:
    bool dfs(int i, int j, int k, map<pair<int, int>, bool> &dp, string &s1, string &s2, string &s3){
        if(k == s3.size()) return i == s1.size() && j == s2.size();
        if(dp.count({i, j})) return dp[{i, j}];
        bool res = false;
        if(i < s1.size() && s3[k]==s1[i]) res = dfs(i+1, j, k+1, dp, s1, s2, s3);
        if(!res && j < s2.size() && s2[j] == s3[k]) res = dfs(i, j+1, k+1, dp, s1, s2, s3);
        // if(s3[k]!=s1[i] && s3[k]!=s2[j]) res = dfs(i+1, j+1, k, dp, s1, s2, s3);
        // if(s3[k]==s1[i] && s3[k]==s2[j]) res = dfs(i+1, j+1, k+1, dp, s1, s2, s3);
        return dp[{i, j}] = res;

    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) return false;
        map<pair<int, int>, bool> dp;
        return dfs(0, 0, 0, dp, s1, s2, s3);
    }
};
