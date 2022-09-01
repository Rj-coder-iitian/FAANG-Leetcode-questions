class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end()), vis;
        if(!words.count(endWord))
            return 0;
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int steps = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return steps;
                for(int i=0;i<word.length();i++){
                    string temp = word;
                    for(int j=0;j<26;j++){
                        temp[i] = 'a' + j;
                        if(!vis.count(temp) && words.count(temp)){
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};