import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def bfs(root: TreeNode):
    res = []

    q = collections.deque()
    q.append(root)

    while q:
        qLen = len(q)
        levelValues = []

        for i in range(qLen):
            node = q.popleft()
            if node:
                levelValues.append(node.val)
                q.append(node.left)
                q.append(node.right)

        if levelValues:
            res.append(levelValues)

    return res


