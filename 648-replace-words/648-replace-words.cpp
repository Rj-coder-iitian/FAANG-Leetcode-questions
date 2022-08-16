// class TrieNode {
// public:
//     bool isEnd;
//     TrieNode* children[26];
//     TrieNode() {
//         isEnd = false;
//         memset(children, NULL, sizeof(children));
//     }
// };

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st;
        for(auto word : dictionary){
            st.insert(word);
        }
        string result = "";
        int size = sentence.size();
        string str = "";
        for(int i=0;i<size;i++){
            if(sentence[i] == ' '){
                result += (str + ' ');
                str = "";
                continue;
            }
            str += sentence[i];
            if(st.find(str) != st.end()) {
                while(i<size && sentence[i] != ' '){
                    i++;
                }
                result += str;
                str = "";
                if(i != size)
                    result += ' ';
            }
        }
        if(str != "")
            result += str;
        return result;
    }
// private:
//     TrieNode* root = new TrieNode();
};