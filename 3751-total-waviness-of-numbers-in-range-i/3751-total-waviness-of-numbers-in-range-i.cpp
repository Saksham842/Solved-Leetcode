class Solution {
    int isPeak(int i)
    {
        string str=to_string(i);
        int tp=0;
        if(str.length()<3) return 0;
        for(int k=1;k<str.length()-1;k++)
        {
            if(str[k-1]<str[k] && str[k]>str[k+1]) tp++;
        }
        return tp;
    }
    int isValley(int i)
    {
        string str=to_string(i);
        int tp=0;
        if(str.length()<3) return 0;
        for(int k=1;k<str.length()-1;k++)
        {
            if(str[k-1]>str[k] && str[k]<str[k+1]) tp++;
        }
        return tp;
    }
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++)
        {
            if(isPeak(i)) ans+=isPeak(i);
            if(isValley(i)) ans+=isValley(i);
        }
        return ans;
    }
};