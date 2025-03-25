# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        res=[]
        curr=head
        while curr:
            res.append(curr.val)
            curr=curr.next   
        def check(res):
            n=len(res)
            s=0
            e=n-1
            while(s<e):
                if res[s]!=res[e]:
                    return False
                s+=1
                e-=1        
            return True 
        return check(res)            