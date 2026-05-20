class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       unordered_map<int,int>m1;
       unordered_map<int,int>m2;
       vector<int>ans(A.size(),0);
       for(int i=0;i<A.size();i++)
       {
            if(A[i]==B[i]) 
            {   
                if(i==0) ans[i]+=1;
                else ans[i]=ans[i-1]+1;
            }
            else
            {
                m1[A[i]]=i;
                m2[B[i]]=i;
                if(i!=0) ans[i]+=ans[i-1];
                if(m1.find(B[i])!=m1.end()) ans[i]+=1;
                if(m2.find(A[i])!=m2.end()) ans[i]+=1;
            }
       }
        return ans;
    }
};