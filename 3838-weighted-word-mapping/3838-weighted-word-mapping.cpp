class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string val:words){
            int k=0;
            for(int i=0;i<val.length();i++){
                k+=weights[val[i]-'a'];
                k%=26;
            }
            char c=26-k+96;
            ans+=c;
        }
        return ans;
    }
};