class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       unordered_map<int,int>m1;
       vector<int>ans(A.size(),0);
       int count=0;
       for(int i=0;i<A.size();i++)
       {
                m1[A[i]]++;
                if(m1[A[i]]==2) count++;
                m1[B[i]]++;
                if(m1[B[i]]==2) count++;
                ans[i]=count;
            
       }
        return ans;
    }
};