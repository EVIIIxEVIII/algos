
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        current_node = root
        res = 0

        s, b = min(p.val, q.val), max(p.val, q.val)

        while current_node is not None:
            if current_node.val < s and current_node.val < b:
                current_node = current_node.right

            elif current_node.val > s and current_node.val > b:
                current_node = current_node.left

            else:
                res = current_node
                break

        return res
