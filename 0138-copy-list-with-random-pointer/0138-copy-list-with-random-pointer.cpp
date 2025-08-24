/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        unordered_map<Node*, Node*> old_to_new;
        Node* temp = head;
        while (temp != NULL) {
            old_to_new[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp=head;
        while(temp){
            old_to_new[temp]->next=old_to_new[temp->next];
            old_to_new[temp]->random=old_to_new[temp->random];
            temp=temp->next;
        }
        return old_to_new[head];
        
    }
};