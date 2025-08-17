class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode], min=None, max=None) -> bool:
        if min is None or max is None:
            min = float('-inf')
            max = float('inf')

        if min >= root.val or max <= root.val:
            return False

        left = self.isValidBST(root.left, min, root.val)
        right = self.isValidBST(root.right, root.val, max)

        return left and right

