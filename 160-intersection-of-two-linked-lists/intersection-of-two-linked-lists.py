# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        mpp={}
        curr=headA
        while curr:
            mpp[curr]=1
            curr=curr.next
        curr=headB
        while curr:
            if curr in mpp:
                return curr
            curr=curr.next    
        return None            
