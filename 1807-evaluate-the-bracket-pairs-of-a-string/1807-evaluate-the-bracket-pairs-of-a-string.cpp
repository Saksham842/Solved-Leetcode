class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for(auto x : knowledge){
            mp[x[0]] = x[1];
        }

        string ans = "";

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                string temp = "";
                int j = i + 1;

                while(s[j] != ')'){
                    temp += s[j];
                    j++;
                }

                if(mp.find(temp) != mp.end())
                    ans += mp[temp];
                else
                    ans += "?";

                i = j;
            }
            else{
                ans += s[i];
            }
        }

        return ans;
    }
};