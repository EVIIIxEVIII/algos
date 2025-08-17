from collections import defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        res = [0, len(s)+1]

        have = defaultdict(int)
        need = defaultdict(int)

        for i in range(len(t)):
            need[t[i]] += 1

        have_count = 0
        need_count = len(need)

        l = 0
        r = 0

        for i in range(2*(len(s) + len(t))):
            if r == len(s):
                break

            if (s[r] in need) and (have_count != need_count):
                have[s[r]] += 1
                if have[s[r]] == need[s[r]]:
                    have_count += 1

            if have_count == need_count:
                if res[1] - res[0] + 1 > r - l + 1:
                    res = [l, r]
                if s[l] in need:
                    have[s[l]] -= 1
                    if have[s[l]] < need[s[l]]:
                        have_count -= 1
                        r += 1
                l += 1
            else:
                r += 1

        if res[1] > len(s):
            return ""
        return s[res[0]:res[1]+1]


solution = Solution()
print(solution.minWindow("ADOBECODEBANC", "ABC"))
