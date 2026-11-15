// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         vector<int> res;
//         int ind1 = 1;
//         int ind2 = ind1+1;
//         while(ind1<numbers.size()){
//             for(ind2 = ind1+1; ind2<=numbers.size(); ind2++){
//                 if(numbers[ind1]+numbers[ind2]==target){
//                     res.push_back(ind1);
//                     res.push_back(ind2);
//                 }
//                 ind1++;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = (numbers.size()) - 1;

        while (left < right) {
            long long sum = (long long)(numbers[left])
                          + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }

            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};
