class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();

        if (k > n) return false;

        array<int, 26> need{};
        array<int, 26> window{};

        for (int i = 0; i < k; i++) {
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        if (window == need) return true;

        for (int right = k; right < n; right++) {
            window[s2[right] - 'a']++;       // Entering character
            window[s2[right - k] - 'a']--;   // Leaving character

            if (window == need) return true;
        }

        return false;
    }
};