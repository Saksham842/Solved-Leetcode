class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>s;
        int ans=0;
        for(char val:word)
        {
            if(val<=90 && val>=65)
            {
                if(s.find(val)!=s.end()) continue;
                if(s.find(val+32)!=s.end()) ans++;
                s.insert(val);
            }
            else
            {
                if(s.find(val)!=s.end()) continue;
                if(s.find(val-32)!=s.end()) ans++;
                s.insert(val);
            }
        }
        return ans;
    }
};