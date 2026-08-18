class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i]+nums[j]==target)
        //         {
        //           return {i,j};
        //         }
                
        //     }
        // }
        //  return {};
        unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};


    }
   
};

