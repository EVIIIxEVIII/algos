class Solution:
    def combinationSum(self, candidates, target):
        sets = []

        def sum_(index, subSum = 0, subset = []):
            nonlocal sets
            if subSum > target:
                return

            if subSum == target:
                sets.append(subset[:])
                return

            for i in range(index, len(candidates)):
                subset.append(candidates[i])
                sum_(i, subSum + candidates[i], subset)
                subset.pop()

        sum_(0, 0, [])
        return sets


solution = Solution()
sol = solution.combinationSum([2, 3, 5], 8)
print(sol)
