class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> hashmap;
        for(int i = 0; i<s.size(); i++){
            hashmap[s[i]] = max(hashmap[s[i]], i);
        }
        vector<int> ans;
        int i = 0;
        while(i<s.size()){
            int size = 0;
            int start = i;
            int end = hashmap[s[i]];
            for(int j = i+1; j<end; j++){
                end = max(end, hashmap[s[j]]);
            }
            size = end-start+1;
            i = end+1;
            ans.push_back(size);
        }
        return ans;
    }
};
