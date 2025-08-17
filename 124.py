class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right


class Solution:
    def maxPathSum(self, root):
        globalMax = float('-inf')
        def dfs(node):
            nonlocal globalMax
            if node is None:
                return 0

            sum_right = dfs(node.right)
            sum_left = dfs(node.left)
            globalMax = max(globalMax, sum_left + sum_right + node.val, node.val, sum_left, sum_right)

            return max(sum_right, sum_left) + node.val

        dfs(root)
        return globalMax



solution = Solution()
solution.maxPathSum(
    TreeNode(1,
             TreeNode(),
             TreeNode(),
    ))

