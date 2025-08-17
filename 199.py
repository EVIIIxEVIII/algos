class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode], memo = None) -> List[int]:
        right = self.rightMost(root)
        longest = self.dfs(root)

        if len(longest) > len(right):
            for i in range(len(right), len(longest)):
                right.append(longest[i])

        return right

    def dfs(self, root):
        if not root:
            return []

        right = self.dfs(root.left)
        left = self.dfs(root.right)

        if len(left) > len(right):
            longest_branch = left
        else:
            longest_branch = right

        return [root.val] + longest_branch

    def rightMost(self, root, memo=None):
        if not memo:
            memo = []

        if not root:
            return memo

        memo.append(root.val)
        memo = self.rightMost(root.right)

        return memo
