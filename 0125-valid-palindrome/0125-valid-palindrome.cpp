class Solution {
public:
    bool isPalindrome(string s) {
        int i =0;
        int j=s.length()-1;
        while(i<=j){
            if(isalpha(s[i]) || isdigit(s[i])){
                if(isalpha(s[j]) || isdigit(s[j])){
                    if(tolower(s[i])!=tolower(s[j])) return false;
                    else {i++;j--;}
                }
                else j--;
            }
            else i++;
        }
        return true;
    }
};