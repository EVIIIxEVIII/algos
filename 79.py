class Solution:
    def exist(self, board, word):
        rows, cols = len(board), len(board[0])

        def backtrack(row, col, i):
            if i == len(word):
                return True

            if row < 0 or row >= rows or col < 0 or col >= cols or board[row][col] != word[i]:
                return False

            temp, board[row][col] = board[row][col], "#"

            found = (
                backtrack(row + 1, col, i + 1) or
                backtrack(row - 1, col, i + 1) or
                backtrack(row, col + 1, i + 1) or
                backtrack(row, col - 1, i + 1)
            )

            board[row][col] = temp
            return found


        for i in range(rows):
            for j in range(cols):
                if backtrack(i, j, 0):
                    return True

        return False


solution = Solution()
res = solution.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCB")
print(res)
