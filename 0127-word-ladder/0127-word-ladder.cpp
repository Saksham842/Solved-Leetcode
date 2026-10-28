class Solution {
public:
    int n;

    bool check(string a, string b) {
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size();

       if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(check(wordList[i], wordList[j])) {
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(check(beginWord, wordList[i])) {
                mp[beginWord].push_back(wordList[i]);
            }
        }

        queue<string> q;
        
        vector<bool>visited(n+1,false);

        q.push(beginWord);
        visited[n] = true;

        int steps = 1;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                string word = q.front();
                q.pop();

                if(word == endWord) return steps;

                for(string next : mp[word]) {
                    int idx = -1;

                    for(int i = 0; i < n; i++) {
                        if(wordList[i] == next) {
                            idx = i;
                            break;
                        }
                    }

                    if(idx != -1 && !visited[idx]) {
                        visited[idx] = true;
                        q.push(next);
                    }
                }
            }

            steps++;
        }

        return 0;
    }
};