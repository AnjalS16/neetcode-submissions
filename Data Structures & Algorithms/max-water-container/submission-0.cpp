class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n-1;
        int maxsum = 0;
        while(left<right){
            int water = min(heights[left], heights[right]) * (right-left);
            maxsum = max(maxsum, water);
            if(heights[left]<=heights[right]) left++;
            else right--;
        }
        return maxsum;
    }
};
