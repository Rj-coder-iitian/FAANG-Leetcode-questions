//Question :-
// Leetcode 863 
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Given the root of a binary tree, the value of a target node target, and an integer k, 
// return an array of the values of all nodes that have a distance k from the target node.


import java.util.List;
import java.util.ArrayList;

public class All_Nodes_Distance_K_BT {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    public List<Integer> distanceK_solution(TreeNode root, TreeNode target, int K) {
        List<Integer> ans = new ArrayList<>();
        distanceK_solution(root, target, K, ans);
        return ans;
    }

    public int distanceK_solution(TreeNode node, TreeNode target, int K, List<Integer> ans) {
        if (node == null)
            return -1;

        if (node == target) {
            KDown(node, null, K, ans);
            return 1;
        }

        int lans = distanceK_solution(node.left, target, K, ans);
        if (lans != -1) {
            KDown(node, node.left, K - lans, ans);
            return lans + 1;
        }

        int rans = distanceK_solution(node.right, target, K, ans);
        if (rans != -1) {
            KDown(node, node.right, K - rans, ans);
            return rans + 1;
        }

        return -1;
    }

    public void KDown(TreeNode node, TreeNode block, int depth, List<Integer> ans) {
        if (node == null || depth < 0 || node == block)
            return;

        if (depth == 0) {
            ans.add(node.val);
            return;
        }

        KDown(node.left, block, depth - 1, ans);
        KDown(node.right, block, depth - 1, ans);
    }
}
