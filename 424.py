class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if(len(s) == 1):
            return 1

        l, r = 0, 1

        res = 0
        temp_res = 0

        chars_map = {}

        most_common = s[l]
        chars_map[s[l]] = 1

        for i in range(len(s) - 1):
            if s[r] not in chars_map:
                chars_map[s[r]] = 1
            else:
                chars_map[s[r]] += 1

            if chars_map[most_common] < chars_map[s[r]]:
                most_common = s[r]

            if (r - l + 1) - chars_map[most_common] > k:
                chars_map[s[l]] -= 1
                l += 1

            res = max(res, r - l + 1)
            r += 1

        return res

solution = Solution()
print(solution.characterReplacement(
    "A",
    1
))

