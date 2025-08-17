import math

class Solution:
    def search(self, nums: list[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = (r + l) // 2

            if nums[mid] == target:
                return mid;

            if nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1

        return -1;



solution = Solution()
print(solution.search([2, 5], 5));
