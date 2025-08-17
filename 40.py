class Solution:
    def combinationSum(self, candidates, target):
        sets = []

        candidates = sorted(candidates)
        def sum_(index, subSum = 0, subset = []):
            nonlocal sets
            if subSum == target:
                sets.append(subset[:])
                return

            if subSum > target:
                return

            i = 0
            for i in range(index, len(candidates)):
                if i > index and candidates[i] == candidates[i - 1]:
                    continue

                sum_(i + 1, subSum + candidates[i], subset + [candidates[i]])
                i+=1

        sum_(0, 0, [])
        return sets


solution = Solution()
sol = solution.combinationSum([10,1,2,7,6,1,5], 8)
print(sol)
