# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root):
        if root is None:
            return []

        queue = [root]
        res = []
        tempQueue = []
        tempRes = []

        while True:
            if len(queue) == 0 and len(tempQueue) == 0: break

            if len(queue) == 0:
                queue = tempQueue;
                res.append(tempRes);

                tempQueue = []
                tempRes = []

            node = queue[0];

            if node.left is not None:
                tempQueue.append(node.left)
            if node.right is not None:
                tempQueue.append(node.right)

            tempRes.append(node.val);
            queue.pop(0)

        if len(tempRes) > 0:
            res.append(tempRes)

        return res

