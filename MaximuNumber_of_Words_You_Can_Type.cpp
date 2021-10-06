class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> vec(26, 0);
        for(int i=0;i<brokenLetters.length();i++){
            vec[brokenLetters[i]-'a'] = 1;
        }
        istringstream ss(text);
        string word; // for storing each word
        int count = 0;
        while (ss >> word) 
        {
            bool flag = false;
            for(int i=0;i<word.length();i++){
                if(vec[word[i]-'a'] == 1){
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;
            else
                count++;
            // cout << word << "\n";
        }
        return count;
    }
};
