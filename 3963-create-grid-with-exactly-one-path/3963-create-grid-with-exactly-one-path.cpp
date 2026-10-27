class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        string str="";
        string str1="";
        for(int i=0 ; i<n ;i++) str+='.';
        ans.push_back(str);
        for(int i=0 ; i<n-1 ;i++) str1+='#';
        str1+='.';
         for(int j=0;j<m-1;j++) ans.push_back(str1);
        return ans;
        
    }
};