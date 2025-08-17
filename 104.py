from types import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode], num = 0) -> int:
        if root == None: return num

        leftside = self.maxDepth(root.left, num+1)
        rightside = self.maxDepth(root.right, num+1)

        return max(leftside, rightside)




