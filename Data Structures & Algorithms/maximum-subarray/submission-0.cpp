class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = INT_MIN;
        int currsum = 0;
        for(int i = 0; i<n; i++){
            currsum = max(nums[i], currsum + nums[i]);
            sum = max(sum, currsum);
        }
        return sum;
    }
};
