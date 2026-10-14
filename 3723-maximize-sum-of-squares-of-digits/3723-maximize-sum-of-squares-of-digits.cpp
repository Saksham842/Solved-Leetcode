class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while(num>0){
            if(sum>8){
                ans+='9';
                sum-=9;
            }
            else{
                ans+=to_string(sum);
                sum=0;
            }
            num--;
        }
        if(sum!=0) return "";
        return ans;
    }
};