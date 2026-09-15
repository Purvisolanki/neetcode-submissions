class Solution {
public:
    bool isValid(char ch)
    {
        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
            return 1;
        }
        else{
            return 0;
        }
    }
    
char toLowerCase(char ch){
    if(ch >='a' && ch <= 'z')
      return ch;
      else{
          char temp = ch - 'A' + 'a';
          return temp;
      }
}

    bool isPalindrome(string s) {
         int st = 0,e = s.size() - 1;
          while(st<=e){
            if(!isValid(s[st]))
                st++;
            else if(!isValid(s[e]))
                e--;
            else if(toLowerCase(s[st]) != toLowerCase(s[e])){
                return 0;
            }
            else
            {
                st++;e--;
            }
        }
        return 1;
    }
};