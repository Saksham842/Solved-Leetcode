class Solution {
public:
    bool checkString(string s) {
        bool ans=true;
        for(char c:s){
            if(c=='a' && ans==false) return false;
            if(c=='b') ans=false;
        }
        return true;
    }
};