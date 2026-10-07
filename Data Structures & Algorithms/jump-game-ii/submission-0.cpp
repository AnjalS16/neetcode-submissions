class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        int cnt = 0;
        int end = 0;
        for(int i = 0; i<n-1; i++){
            //if(i>farthest) return -1;
            farthest = max(farthest, i+nums[i]);
            if(i==end){
                cnt++;
                end = farthest;
            }
        }
        return cnt;
    }
};
