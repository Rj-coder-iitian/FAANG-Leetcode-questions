class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int node_count = 1, level = 1;
        while(label >= node_count * 2){
            node_count *= 2;
            level++;
        }
        while(label != 0){
            ans.push_back(label);
            int max_node = pow(2, level) - 1;
            int min_node = pow(2, level - 1);
            label = (max_node + min_node - label)/2;
            level--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};