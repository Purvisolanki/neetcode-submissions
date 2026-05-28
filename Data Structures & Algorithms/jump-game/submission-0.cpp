#include<cstring>
class Solution {
public:
    int n;
    int t[10001];

    bool function(vector<int>& nums, int ind) {
        // 1. Move the Win condition to the top
        if (ind >= n - 1) return true;

        // 2. Memo check (now safe because ind is guaranteed < n-1)
        if (t[ind] != -1) return t[ind];

        // 3. Reverse the loop to try the longest jumps first
        for (int i = nums[ind]; i >= 1; i--) { 
            if (function(nums, ind + i)) {
                return t[ind] = true;
            }
        }

        return t[ind] = false;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();
        // Use a smaller memset if possible, or just reset based on n
        memset(t, -1, sizeof(t));
        return function(nums, 0);
    }
};