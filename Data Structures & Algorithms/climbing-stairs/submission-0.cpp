class Solution {
public:
    int dp(int i, vector<int>& cache, int n){
        if(i==n) return 1;
        if(i>n) return 0;
        if(cache[i]!=-1) return cache[i];
        cache[i] = dp(i+1, cache, n) + dp(i+2, cache, n);
        return cache[i];
    }
    int climbStairs(int n) {
        vector<int> cache(n, -1);
        //cache[0] = 1;
        return dp(0, cache, n);
    }
};
