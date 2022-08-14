/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<Node*> q;
        q.push(root);
        while(q.empty() == false) {
            int n = q.size();
            vector<int> sol;
            for(int i=0;i<n;i++) {
                Node* curr = q.front();
                q.pop();
                sol.push_back(curr->val);
                for(auto child: curr->children) {
                    if(child)
                        q.push(child);
                }
            }
            ans.push_back(sol);
        }
        return ans;
    }
};