/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num=0;
        ListNode*temp=head;
        while(temp!=NULL){
            num++;
            temp=temp->next;
        }
        if(n==num){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        ListNode*prev=head;
        ListNode*temp1=head;
        for(int i=0;i<(num-n);i++){
            prev=temp1;
            temp1=temp1->next;
        }
        prev->next=temp1->next;
        return head;
    }
};