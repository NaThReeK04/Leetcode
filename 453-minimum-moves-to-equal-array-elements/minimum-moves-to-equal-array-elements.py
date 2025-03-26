class Solution:
    def minMoves(self, nums: List[int]) -> int:
        num=min(nums)
        ans=0
        for i in range(len(nums)):
            ans+=nums[i]-num
        return ans    