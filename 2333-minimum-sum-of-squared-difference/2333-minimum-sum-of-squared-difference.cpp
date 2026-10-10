class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        map<int,int,greater<int>>mp;
        for(int i=0;i<nums1.size();i++){
            mp[abs(nums1[i]-nums2[i])]++;
        }
        int n=k1+k2;
        for(auto x:mp){
            int key=x.first;
            int val=x.second;
            if(n<=0 || key<=0) break;
            if(n>=val){
                if(mp.count(key-1)) mp[key-1]+=val;
                else mp[key-1]=val;
                n-=val;
                mp.erase(key);
            }
            else{
                mp[key]-=n;
                if(mp.count(key-1)) mp[key-1]+=n;
                else mp[key-1]=n;
                n=0;
            }
        }
        long long ans=0;
        for(auto x:mp){
            int key=x.first;
            int val=x.second;
            ans+=(long long)key*key*val;
        }
        return ans;
    }
};