class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int curmax = 1;
        int curmin = 1;
        for(int num : nums){
            int temp = curmax*num;
            curmax = max({num, num*curmax, num*curmin});
            curmin = min({num, temp, num*curmin});
            res = max(res, curmax);
        }
        return res;
    }
};
