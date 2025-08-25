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
    ListNode* reverse(ListNode* curr,ListNode*end){
        ListNode* prev=nullptr;
        while(curr!=end){
            ListNode*nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return nullptr;
        ListNode* temp=head;
        for(int i=0;i<k;++i){
            if(!temp)return head;
            temp=temp->next;
        }
        ListNode* newhead=reverse(head,temp);
        head->next=reverseKGroup(temp,k);
        return newhead;
    }
};