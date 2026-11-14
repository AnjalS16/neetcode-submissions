class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int rlow = 0;
        int rhigh = m-1;
        while(rlow<=rhigh){
            int mid = (rlow+rhigh)/2;
            if(matrix[mid][n-1]==target) return true;
            else if(matrix[mid][n-1]>target){
                rhigh = mid-1;
            }
            else rlow = mid+1;
        }
        if (rlow == m) return false;
        int clow = 0;
        int chigh = n-1;
        while(clow<=chigh){
            int mid = (clow+chigh)/2;
            if(matrix[rlow][mid]==target) return true;
            else if(matrix[rlow][mid]>target){
                chigh = mid-1;
            }
            else clow = mid+1;
        }
        return false;
    }
};
