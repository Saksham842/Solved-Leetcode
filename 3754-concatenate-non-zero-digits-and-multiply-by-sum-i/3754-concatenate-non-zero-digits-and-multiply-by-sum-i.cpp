class Solution {
public:
    long long sumAndMultiply(int n) {
        int x=0,sum=0,temp=1;
        while(n>0)
        {
            int digit=n%10;
            if(digit!=0)
            {
                x=x+digit*temp;
                temp*=10;
            }
            n=n/10;
        }
        int k=x;
        while(k>0)
        {
            sum+=k%10;
            k=k/10;
        }
        return (long long)x*sum;
    }
};