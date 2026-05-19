class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int val:nums1)
        {
            int st=0;
            int end=nums2.size()-1;
            while(st<=end)
            {
                int mid=st + (end-st)/2 ;
                if(nums2[mid]==val) return nums2[mid];
                else if(nums2[mid]>val) end=mid-1;
                else st=mid+1;
            }
        }
        return -1;
    }
};