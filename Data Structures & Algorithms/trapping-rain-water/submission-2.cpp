class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> premax(n);
        vector<int> sufmax(n);

        premax[0] = height[0];

        for (int i = 1; i < n; i++) {
            premax[i] = max(premax[i - 1], height[i]);
        }

        sufmax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sufmax[i] = max(sufmax[i + 1], height[i]);
        }

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += min(premax[i], sufmax[i]) - height[i];
        }

        return sum;
    }
};