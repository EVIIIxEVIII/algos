class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        stack = [["(", 1, 0]]
        res = []

        i = 0

        while i < len(stack):
            [string, open, closed] = stack[i]

            if open == closed == n:
                res.append(string)
                i += 1
                continue

            if open == n:
                stack.append([string + ")", open, closed + 1])
                i += 1
                continue

            if open > closed:
                stack.append([string + ")", open, closed + 1])
                stack.append([string + "(", open+1, closed])
            else:
                stack.append([string + "(", open+1, closed])

            i += 1

        return res


solution = Solution()

print(solution.generateParenthesis(3))
