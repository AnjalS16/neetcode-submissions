class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int index = -1;
        int pivot;
        while(low < high){
            int m = (low+high)/2;
            if(nums[m] > nums[high]) low = m+1;
            else high = m;
        }
        pivot = low;
        if (nums[pivot] <= target && target <= nums[n - 1]) {
            low = pivot;
            high = n - 1;
        } else {
            low = 0;
            high = pivot - 1;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;

            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return index;
    }
};
