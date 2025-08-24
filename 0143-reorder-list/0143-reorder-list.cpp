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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow=head;
        ListNode* fast=head;

        //find the middle node
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        //reverse the second half
        ListNode*prev1=NULL;
        ListNode*curr=slow;
        ListNode*nex=slow;

        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev1;
            prev1=curr;
            curr=nex;
        }
        //now merging the both
        ListNode* first=head;
        ListNode*second=prev1;
        while(second->next!=NULL){
            ListNode*temp1=first->next;
            ListNode*temp2=second->next;

            first->next=second;
            second->next=temp1;

            first=temp1;
            second=temp2;
        }

    }
};