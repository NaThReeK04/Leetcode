# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
         curr=dummy=ListNode()
         extra=0
         while l1 and l2:
            sum=l1.val+l2.val+extra
            extra=sum//10
            sum=sum%10
            curr.next=ListNode(sum)
            curr=curr.next
            l1=l1.next
            l2=l2.next
         while l1 or l2:
            sum=(l1.val if l1 else l2.val)+extra
            extra=sum//10
            sum=sum%10
            curr.next=ListNode(sum)
            curr=curr.next
            l1=l1.next if l1 else None
            l2=l2.next if l2 else None
         if extra:
            curr.next=ListNode(extra)    
         return dummy.next    