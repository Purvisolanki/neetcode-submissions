// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
        
//         int product = 1;
//         int zeroCount = 0;

//         // Calculate product of non-zero elements
//         for(int num : nums) {
//             if(num == 0) {
//                 zeroCount++;
//             } else {
//                 product *= num;
//             }
//         }

//         vector<int> res;

//         for(int num : nums) {

//             // More than one zero
//             if(zeroCount > 1) {
//                 res.push_back(0);
//             }

//             // Exactly one zero
//             else if(zeroCount == 1) {
//                 if(num == 0)
//                     res.push_back(product);
//                 else
//                     res.push_back(0);
//             }

//             // No zero
//             else {
//                 res.push_back(product / num);
//             }
//         }

//         return res;
//     }
// };


//Approach-3 (Using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0] = 1;
        
        for(int i = 1; i<nums.size(); i++) {
            result[i] = result[i-1]*nums[i-1];
        }
        
        int right = 1;
        for(int i = n-1; i>=0; i--) {
            result[i] = result[i]*right;
            right *= nums[i];
        }
        
        return result;
    }
};