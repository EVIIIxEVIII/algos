class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def goodNodes(self, root: TreeNode, max=0) -> int:
        if not root:
            return 0

        left = self.goodNodes(root.left, max(root.val, max))
        right = self.goodNodes(root.right, max(root.val, max))

        return 1 + left + right if root.val < max else right + left



