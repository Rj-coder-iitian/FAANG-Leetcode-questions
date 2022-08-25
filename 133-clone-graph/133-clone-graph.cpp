/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraphUtil(Node* node, unordered_map<Node*, Node*>& mp) {
        Node* clone = new Node(node->val);
        vector<Node*> nbr;
        mp[node] = clone;
        for(auto n: node->neighbors) {
            if(mp.find(n) != mp.end()){
                nbr.push_back(mp[n]);
            } else {
                nbr.push_back(cloneGraphUtil(n, mp));
            }
        }
        clone->neighbors = nbr;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        if(node->neighbors.size() == 0){
            Node* clone = new Node(node->val);
            return clone;
        }
        unordered_map<Node*, Node*> mp;
        return cloneGraphUtil(node, mp);
    }
};