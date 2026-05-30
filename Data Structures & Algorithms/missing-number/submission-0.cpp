class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //1- brute force
        // int n = nums.size();
        // return n*(n+1)*0.5 - accumulate(nums.begin(),nums.end(),0);

        //2-optimal
         int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        for(int i=1;i<=nums.size();i++){
            ans=ans^i;
        }
        return ans;
    }
};