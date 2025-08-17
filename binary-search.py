
def search(nums, t):
    l, r = 0, len(nums) - 1

    while l <= r:
        mid = (r + l) // 2

        if nums[mid] == t:
            return mid

        if nums[mid] > t:
            r = mid - 1
        else:
            l = mid + 1

        return -1


print(search([1, 2, 3, 4, 5, 6], 3))
