class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hashmap;
        for(int num : nums) hashmap[num]++;
        int maxcnt = 0;
        for(int i = 0; i<n; i++){
            int cnt = 1;
            int num = nums[i];
            if(hashmap.find(num-1) != hashmap.end()) continue;
            while(hashmap.find(num+1) != hashmap.end()){
                cnt++;
                num++;
            }
            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;
    }
};
