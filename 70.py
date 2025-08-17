# top to bottom approach
#class Solution:
#    def climbStairs(self, n, memo={}):
#        if (n == 0):
#            return 1
#
#        if (memo.get(n) is not None):
#            return memo.get(n)
#
#        n2 = 0
#        n1 = self.climbStairs(n - 1, memo)
#        if (n - 2 >= 0):
#            n2 = self.climbStairs(n - 2, memo)
#
#        memo[n] = n1 + n2
#        return n1 + n2

# bottom to top approach
class Solution:
    def climbStairs(self, n):
        grid = [1, 2]

        if n == 1: return 1
        if n == 2: return 2

        temp = 0
        for _ in range(3, n + 1):
            temp = grid[1] + grid[0]
            grid[0] = grid[1]
            grid[1] = temp

        return temp




solution = Solution()
print(solution.climbStairs(1))
print(solution.climbStairs(2))
print(solution.climbStairs(3))
print(solution.climbStairs(4))
print(solution.climbStairs(5))
print(solution.climbStairs(6))
