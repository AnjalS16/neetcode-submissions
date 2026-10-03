class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int residx = 0;
        int reslen = 0;
        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1]==true)){
                    dp[i][j] = true;
                    if (j - i + 1 > reslen) {
                        reslen = j - i + 1;
                        residx = i;
                    }
                }
            }
        }
        return s.substr(residx, reslen);
    }
};
