class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>vec;
        string ans="";
        for(int i=0;i<nums.size();i++) vec.push_back(to_string(nums[i]));
        sort(vec.begin(),vec.end(),[](string&a,string&b){
            return a+b>b+a;
        });
        if(vec[0]=="0") return "0";
        for(int i=0;i<vec.size();i++) ans+=vec[i];
        return ans;
    }
};