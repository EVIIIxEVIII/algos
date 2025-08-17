class Solution:
    def partition(self, s):
        res = []

        def backtrack(i, offset, temp):
            nonlocal res
            if (i - offset) < 0 or (i + offset) >= len(s):
                return False

            temp = []
            if s[i + offset] == s[i - offset]:
                temp.append(s[i-offset:i+offset+1])
                backtrack(i, offset+1, temp)

            res.append(temp)

        for i in range(len(s)):
            backtrack(i, 0, [])

        return res


solution = Solution()
print(solution.partition("abacdca"))
print(solution.partition("aab"))
