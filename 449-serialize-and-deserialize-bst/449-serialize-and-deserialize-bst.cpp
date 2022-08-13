/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right); 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for(int i=0;i<data.size();i++){
            if(data[i] == ','){
                q.push(s);
                s = "";
                continue;
            }
            s += data[i];
        }
        if(s.size() > 0)    q.push(s);
        return deserializeHelper(q);
    }
    TreeNode* deserializeHelper(queue<string>& q){
        string val = q.front();
        q.pop();
        if(val == "#")
            return nullptr;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(q);
        root->right = deserializeHelper(q);
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;