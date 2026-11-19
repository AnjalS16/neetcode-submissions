class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<tuple<int, int, int>> st;
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i<n; i++){
            int target = -nums[i];
            int left = i+1;
            int right = n-1;
            while(left<right){
                if(nums[left]+nums[right]==target){
                    vector<int> prev;
                    prev.insert(prev.end(), {nums[i], nums[left], nums[right]});
                    sort(prev.begin(), prev.end());
                    st.insert({prev[0], prev[1], prev[2]});
                    left++;
                    right--;
                }
                else if(nums[left]+nums[right]>target){
                    right--;
                }
                else left++;
            }
        }
        if(!st.empty()){
            for(const auto& [a, b, c] : st) res.push_back({a, b, c});
        }
        return res;
    }
};
