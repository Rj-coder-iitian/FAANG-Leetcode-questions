#Trim a Binary Search Tree

class Solution:
    def trimBST(self, R: TreeNode, L: int, H: int) -> TreeNode:
        if not R: return R
        if R.val < L: return self.trimBST(R.right,L,H)
        elif R.val > H: return self.trimBST(R.left,L,H)
        R.left = self.trimBST(R.left,L,H)
        R.right = self.trimBST(R.right,L,H)
        return R
