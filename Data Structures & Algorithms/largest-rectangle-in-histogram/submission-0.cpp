class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        
        int maxarea = INT_MIN;
        for(int i = 0; i<=n; i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int height = heights[st.top()];
                st.pop();
                int wid = st.empty()? i : i-st.top()-1;
                maxarea = max(maxarea, height*wid);
            }
            st.push(i);
        }
        return maxarea;
    }
};
