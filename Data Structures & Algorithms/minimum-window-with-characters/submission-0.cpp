class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        if(s==t) return s;
        unordered_map<char, int> target, window;
        for (char c : t) target[c]++;
        int have = 0, need = target.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX, startIdx = 0;

        for (int r = 0, l = 0; r < s.size(); ++r) {
            char c = s[r];
            window[c]++;
            if (target.count(c) && window[c] == target[c])         
                have++;

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }
        
                if (target.count(s[l]) && window[s[l]] == target[s[l]]) have--;
                window[s[l]]--;
                l++;
            }
            
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
