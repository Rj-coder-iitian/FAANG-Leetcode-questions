#Symmetric Tree

class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right
        
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        if not root.left and not root.right:
            return True        
        
        return self.is_mirror(root.left, root.right)
        
    def is_mirror(self, root1, root2):
        if not root1 and not root2:
            return True            

        if not root1 or not root2 or root1.val != root2.val:
            return False
        
        return self.is_mirror(root1.left, root2.right) and self.is_mirror(root1.right, root2.left)
