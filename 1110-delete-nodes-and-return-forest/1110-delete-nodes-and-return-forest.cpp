/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildMap(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, TreeNode*>& mp,  unordered_set<int>& del, unordered_map<int, TreeNode*>& mpVal) {
        if(!root)
            return;
        buildMap(root->left, root, mp, del, mpVal);
        buildMap(root->right, root, mp, del, mpVal);
        if(prev && del.find(prev->val) != del.end()){
            mp[root] = NULL;
        } else
            mp[root] = prev;
        
        mpVal[root->val] = root;
    }
    TreeNode* correctTree(TreeNode* root,  unordered_set<int>& del) {
        if(!root)
            return NULL;
        root->left = correctTree(root->left, del);
        root->right = correctTree(root->right, del);
        if(del.find(root->val) != del.end())
            return NULL;
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<TreeNode*, TreeNode*> mp;
        unordered_map<int, TreeNode*> mpVal;
        unordered_set<int> del;
        for(int node_val: to_delete){
            del.insert(node_val);
        }
        TreeNode* prev = NULL;
        buildMap(root, prev, mp,del, mpVal);
        root = correctTree(root, del);
        for(int node_val: to_delete){
            TreeNode* node = mpVal[node_val];
            mpVal.erase(node_val);
            mp.erase(node);
        }
        vector<TreeNode*> rootArr;
        unordered_set<TreeNode*> st;
        for(auto v = mpVal.begin(); v != mpVal.end(); v++){
            TreeNode* curr = (*v).second;
            while(mp[curr] != NULL) {
                curr = mp[curr];
            }
            st.insert(curr);
        }
        for(auto v = st.begin(); v != st.end(); v++){ 
            rootArr.push_back(*v);
        }
        return rootArr;
    }
};