class Solution {
public:
    string processStr(string s) {
      string result ="";
      for(char ch:s)
      {
        if(ch>=97 && ch<=122) result+=ch;
        else if(ch=='*' && result.length()!=0) result.pop_back();
        else if(ch=='#') result+=result;
        else reverse(result.begin(),result.end());
      }  
      return result;
    }
};