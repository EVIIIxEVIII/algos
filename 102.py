class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode], memo=[], level=0) -> List[List[int]]:
        if root is None:
            return memo

        if len(memo) < level:
            memo[level].append([])

        memo[level].append(root.val)

        self.levelOrder(root.left, memo, level+1)
        self.levelOrder(root.right, memo, level+1)

        return memo
