class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1;
        int end=*max_element(piles.begin(),piles.end());

        int ans=INT_MAX;
        while(st<=end){
            int t=h;
            int mid=st+(end-st)/2;
            for(int i=0;i<piles.size();i++){
                if(piles[i]<mid) t--;
                else if(piles[i]%mid==0) t=t-piles[i]/mid;
                else t-=piles[i]/mid +1 ;
            }
            if(t>=0){
                ans=min(ans,mid);
                end=mid-1;
            } 
            else st=mid+1;
        }
        return ans;
    }
};