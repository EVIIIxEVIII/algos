from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        serializedRoot = self.serialize(root)
        serializedSubRoot = self.serialize(subRoot)

        if serializedSubRoot in serializedRoot:
            return True
        else:
            return False

    def serialize(self, root):
        if not root:
            return "#"

        return f" {root.val},{self.serialize(root.left)},{self.serialize(root.right)}"


