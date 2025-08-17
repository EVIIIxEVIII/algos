from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        l, r = 0, k - 1

        res = []
        d = deque()

        for i in range(0, k):
            while len(d) != 0 and nums[d[-1]] < nums[i]:
                d.pop()
            d.append(i)
        res.append(nums[d[0]])

        l += 1
        r += 1

        for i in range(len(nums)):
            if r > len(nums) - 1:
                break

            if len(d) != 0 and d[0] == l - 1:
                d.popleft()

            while len(d) != 0 and nums[d[-1]] < nums[r]:
                d.pop()

            d.append(r)
            res.append(nums[d[0]])

            l += 1
            r += 1

        return res

solution = Solution()
print(solution.maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3))
