class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        k=len(nums)
        target=nums[k//2]
        ans=0
        for i in range(k):
            diff=abs(nums[i]-target)
            ans+=diff//1
        return ans    