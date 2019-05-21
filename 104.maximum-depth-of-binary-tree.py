class Solution(object):
    def traversal(self, root):
        if root is None:
            return 0x00
        left_depth = right_depth = 0x01
        if root.left is not None:
            left_depth = 1 + self.traversal(root.left)
        if root.right is not None:
            right_depth = 1 + self.traversal(root.right)
        if right_depth > left_depth:
            return right_depth
        return left_depth
    
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0x00
        return self.traversal(root)
