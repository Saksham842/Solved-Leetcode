class Solution {
public:
    int maxNumberOfBalloons(string text) {
       unordered_map<char,int>m;
       int ans=INT_MAX;
       for(char val:text) m[val]++;
         return min({
            m['b'],
            m['a'],
            m['l'] / 2,
            m['o'] / 2,
            m['n']
        });
    }
};