class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerLast(26, -1);
        vector<int> upperFirst(26, -1);
        for(int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if(ch >= 'a' && ch <= 'z')
            {
                lowerLast[ch - 'a'] = i;
            }
            else
            {
                if(upperFirst[ch - 'A'] == -1)
                    upperFirst[ch - 'A'] = i;
            }
        }
        int ans = 0;
        for(int i = 0; i < 26; i++)
        {
            if(lowerLast[i] != -1 &&
               upperFirst[i] != -1 &&
               lowerLast[i] < upperFirst[i])
            {
                ans++;
            }
        }
        return ans;
    }
};