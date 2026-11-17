class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int leftsize = (m+n+1)/2;
        int low = 0;
        int high = m;

        while(low<=high){
            int i = (low+high)/2;
            int j = leftsize - i;
            int aleft = (i==0) ? INT_MIN : nums1[i-1];
            int aright = (i==m) ? INT_MAX : nums1[i];
            int bleft = (j==0) ? INT_MIN : nums2[j-1];
            int bright = (j==n) ? INT_MAX : nums2[j];
            if(aleft > bright) high = i-1;
            else if(bleft > aright) low = i+1;
            else{
                int leftmax = max(aleft, bleft);
                if((m+n)%2==1) return leftmax;
                int rightmin = min(aright, bright);
                return (double)(leftmax+rightmin)/2.0;
            }
        }
        return -1;
    }
};
