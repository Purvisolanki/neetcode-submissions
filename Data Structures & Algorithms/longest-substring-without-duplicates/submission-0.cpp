class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int mx = 0;
        int j = 0;

         for(int i =0;i<s.length();i++){
             mp[s[i]]++;
             while(mp[s[i]]> 1){
                mp[s[j]]--;
                j++;
             }
             mx = max(mx,i-j+1);
         }
         return mx;
    }
};