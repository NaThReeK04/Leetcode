class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        k=len(nums)
        ans=0
        for i in range(k):
            num=nums[i]%3
            ans+=min(num,(3-num))
        return ans    