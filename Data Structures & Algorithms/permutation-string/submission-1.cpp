class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int left = 0;
        int right = left+k-1;
        unordered_map<char, int> mp;
        for(char c : s1){
                mp[c]++;
        }
        while(right<s2.size()){
            unordered_map<char, int> tmp;
            
            for(int i = left; i<=right; i++){
                tmp[s2[i]]++;
            }           
            if(tmp==mp) return true;
            left++;
            right++;
        }
        return false;
    }
};
