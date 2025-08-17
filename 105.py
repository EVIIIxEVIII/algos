class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0 and len(inorder) == 0:
            return None

        root = TreeNode(preorder[0], None, None)
        preorder = preorder[1:]
        inorderIndex = inorder.index(root.val)

        leftInorder = inorder[:inorderIndex]
        rightInorder = inorder[inorderIndex+1:]

        leftPreorder = preorder[:len(leftInorder)]
        rightPreorder = preorder[len(leftInorder):]

        root.left = self.buildTree(leftPreorder, leftInorder)
        root.right = self.buildTree(rightPreorder, rightInorder)

        return root
