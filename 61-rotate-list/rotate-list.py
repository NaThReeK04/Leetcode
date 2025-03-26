# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head==None or head.next==None:return head
        slow=head
        fast=head
        tail=head
        length=0
        while tail:
            length+=1
            tail=tail.next
        k=k%length    
        num=k
        while num!=0:
            fast=fast.next
            num-=1
        while fast and fast.next:
            slow=slow.next
            fast=fast.next
        fast.next=head
        head=slow.next
        slow.next=None
        return head        