class Solution:
    def numIslands(self, grid):
        ans = 0
        rows = len(grid)
        cols = len(grid[0])

        def search(i, j, first_time=False):
            nonlocal ans

            if (grid[i][j] == "0"): return
            if (grid[i][j] == "1" and first_time):
                ans += 1

            grid[i][j] = "0"

            if (i + 1 < rows):
                search(i + 1, j)
            if (i - 1 >= 0):
                search(i - 1, j)
            if (j + 1 < cols):
                search(i, j + 1)
            if (j - 1 >= 0):
                search(i, j - 1)


        for i in range(rows):
            for j in range(cols):
                if(grid[i][j] == "0"): continue
                search(i, j, True)

        return ans


solution = Solution()
print(solution.numIslands((
    ["1","1","1"],
    ["0","1","0"],
    ["1","1","1"]
)))

