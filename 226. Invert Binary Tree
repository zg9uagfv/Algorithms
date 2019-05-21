# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from Queue import Queue

class Solution(object):
    def bfs(self, q):
        list_nodes = []
        while q.empty() == False:
            node = q.get()
            if node is not None:     
                if node.left is not None:
                    q.put(node.left)
                if node.right is not None:
                    q.put(node.right)
            list_nodes.append(node)
        return list_nodes
    
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        q = Queue()
        q.put(root)
        list_nodes = self.bfs(q)
        for node in list_nodes:
            if node is None:
                continue
            tmp = node.left
            node.left = node.right
            node.right = tmp
        return list_nodes[0]
