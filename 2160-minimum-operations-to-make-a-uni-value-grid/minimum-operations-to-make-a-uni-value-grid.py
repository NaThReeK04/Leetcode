class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        num = []
        m = len(grid)
        n = len(grid[0])

        for i in range(m):
            for j in range(n):
                num.append(grid[i][j])

        num.sort()
        ans = 0
        k = len(num)
        target = num[k // 2]  # Median

        for i in range(k):
            diff = abs(num[i] - target)
            if diff % x != 0:
                return -1
            ans += diff // x

        return ans
