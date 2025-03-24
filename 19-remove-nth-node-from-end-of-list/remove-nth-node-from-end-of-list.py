
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        a = 0
        curr = head

        while curr:
            a += 1
            curr = curr.next

        num = a - n 

        if num == 0:
            return head.next  

        a = 0
        prev = None
        curr = head

        while a != num:
            prev = curr
            curr = curr.next
            a += 1    

        prev.next = curr.next
        return head
