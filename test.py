
def search(self, nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1
    mid = (left + right) // 2

    while left <= right:
        if target == nums[mid]:
            return mid

        if left <= mid:
            if nums[left] <= target <= nums[mid]:
                right = mid - 1
            else:
                left = mid + 1

        else:
            if nums[mid] <= target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1

        mid = (left + right) // 2

    return -1


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (target > nums[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l >= 0 && l <= nums.size() - 1 && nums[l] == target ? l : -1;
    }
};
