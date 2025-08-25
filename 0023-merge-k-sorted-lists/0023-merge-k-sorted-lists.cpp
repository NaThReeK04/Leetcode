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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode();
        ListNode*curr=dummy;
        while(true){
            int minList=-1;
            for(int i=0;i<lists.size();i++){
                if(!lists[i])continue;
                if( minList==-1 || lists[minList]->val > lists[i]->val){
                    minList=i;
                }
            }
            if(minList==-1)break;
            curr->next=lists[minList];
            lists[minList]=lists[minList]->next;
            curr=curr->next;
        }
        return dummy->next;
    }
};