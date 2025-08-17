class Solution:
    def subsetsWithDup(self, nums):
        res = []
        nums.sort()

        def backtrack(index, subset):
            nonlocal res

            res.append(subset[:])

            for i in range(index, len(nums)):
                if i > index and nums[i] == nums[i - 1]:
                    continue

                subset.append(nums[i])
                backtrack(i + 1, subset)
                subset.pop()

        backtrack(0, [])

        return res


solution = Solution()
res = solution.subsetsWithDup([1, 2, 3])
print(res)
