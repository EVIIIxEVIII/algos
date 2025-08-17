class Solution:
    def permute(self, nums):
        used = [0]*len(nums)
        print(used)

        res = []
        def backtrack(used, perm):
            nonlocal res
            if len(perm) == len(nums):
                res.append(perm[:])
                return

            for i in range(len(nums)):
                if used[i] == 1: continue
                perm.append(nums[i])
                used[i] = 1
                backtrack(used, perm)
                used[i] = 0
                perm.pop()

        backtrack(used, [])
        return res




solution = Solution()
sol = solution.permute([1, 2, 3])
print(sol)

