from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        res = self.job(root)
        res = True if res != False else False
        return res

    def job(self, root: Optional[TreeNode]):
        if root == None: return 1;

        leftside = self.job(root.left)
        rightside = self.job(root.right)

        if(leftside == False or rightside == False): return False
        if abs(leftside - rightside) > 1: return False

        return max(leftside, rightside) + 1


solution = Solution()

tree1 = TreeNode(3,
        TreeNode(9),
        TreeNode(20, TreeNode(15), TreeNode(7))
)

tree2 = TreeNode(1,
        TreeNode(2,
                 TreeNode(3, TreeNode(4), TreeNode(4)),
                 TreeNode(3),
        ),
        TreeNode(2),
)

print(solution.isBalanced(tree1))
print(solution.isBalanced(tree2))
