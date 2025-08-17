class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int, current_k=None) -> int:
        array = getArray(root, k)


    def getArray(self, root, k):
        res = []

        if not root:
            return []

        left = self.getArray(root.left)
        if len(left) >= k:
            return res

        right = self.getArray(root.right)

        res = left + [root.val] + right
        return res
