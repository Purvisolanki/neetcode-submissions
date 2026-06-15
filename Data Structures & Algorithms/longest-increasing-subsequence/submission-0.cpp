// class Solution {
// public:
// int t[2501][2501];
//     int solve(vector<int>& nums,int i,int P){
//         int an = nums.size();
//         if(i>=n) return 0;

//         if(P != -1 && t[i][P] != -1){
//          return t[i][P];
//         }

//        int take = 0;
//        if(P == -1 || nums[i] > nums[P]){
//         take = 1 + solve(nums, i+1,i);
//        }

//        int skip = solve(nums, i+1,P);

//         if (P != -1){
//             t[i][P] =  max(take,skip);
//         }
//        return max(take,skip);

//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         memset(t , -1 ,sizeof(t));
//         return solve(nums,0,-1);
//     }
// };

//Approach-2 (Bottom Up DP) O(n*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int maxL = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;
    }
};