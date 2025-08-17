import math

class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        small, big = sorted([nums1, nums2], key=len)

        half = math.ceil((len(small) + len(big)) / 2)

        l, r = 0, len(small) - 1
        while True:
            mid = (l + r) // 2
            big_mid = half - mid - 2

            small_left = small[mid] if mid >= 0 else float('-inf')
            small_right = small[mid + 1] if (mid + 1) < len(small) else float('inf')

            big_left = big[big_mid] if big_mid >= 0 else float('-inf')
            big_right = big[big_mid + 1] if (big_mid + 1) < len(big) else float('inf')

            if small_left <= big_right and big_left <= small_right:
                if (len(small) + len(big)) % 2 == 0:
                    return (max(small_left, big_left) + min(small_right, big_right)) / 2
                return max(small_left, big_left)

            elif big_left > small_right:
                l = mid + 1
            else:
                r = mid - 1

solution = Solution()
print(solution.findMedianSortedArrays([1, 2, 3], [1, 7, 8, 9]), 3)
print("-------")
print(solution.findMedianSortedArrays([1, 3], [2]), 2)
print("-------")
print(solution.findMedianSortedArrays([], [1]), 1)
print("-------")
print(solution.findMedianSortedArrays([3], [-2, -1]), -1)
print("-------")
print(solution.findMedianSortedArrays([2], [1, 3]), 2)
print("-------")
print(solution.findMedianSortedArrays([1, 2], [3, 4]), 2.5)
