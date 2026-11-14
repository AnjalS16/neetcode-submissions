class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        sort(piles.begin(), piles.end());
        int res = high;
        while(low<=high){
            int m = low + (high-low)/2;
            long long totaltime = 0;
            for(int p : piles){
                totaltime += ceil((double)p/m);
            }
            if(totaltime <= h){
                res=m;
                high = m-1;
            }
            else low = m+1;
        }
        return res;
    }
};
