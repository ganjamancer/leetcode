class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        listn = ListNode()
        crnt = listn
        c = 0
        
        while l1 or l2 or c:
            sum_val = c
            if l1:
                sum_val += l1.val
                l1 = l1.next
            if l2:
                sum_val += l2.val
                l2 = l2.next
            c = sum_val // 10
            crnt.next = ListNode(sum_val % 10)
            crnt = crnt.next
        
        return listn.next
