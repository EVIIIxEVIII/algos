from types import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    depth = 0

    def diameterOfBinaryTree(self, root: Optional[TreeNode], num = 0) -> int:
        self.depth = 0
        self.job(root)
        return self.depth


    def job(self, root: Optional[TreeNode]) -> int:
        if root == None: return 0

        leftside = self.job(root.left)
        rightside = self.job(root.right)

        self.depth = max(leftside + rightside, self.depth)

        return max(leftside + 1, rightside + 1)
