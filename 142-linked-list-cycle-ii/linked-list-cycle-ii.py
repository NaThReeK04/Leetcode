# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        mpp={}
        curr=head
        while curr:
            if curr in mpp:
                return curr
            mpp[curr]=1
            curr=curr.next
        return None        