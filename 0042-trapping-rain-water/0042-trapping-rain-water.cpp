class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftm=0,rightm=0,l=0,r=n-1,ans=0;
        while(l<r)
        {
            leftm=max(leftm,height[l]);
            rightm=max(rightm,height[r]);
            if(leftm<rightm)
            {
                ans+=leftm-height[l];
                l++;
            }
            else
            {
                ans+=rightm-height[r];
                r--;
            }
        }
        return ans;
    }
};