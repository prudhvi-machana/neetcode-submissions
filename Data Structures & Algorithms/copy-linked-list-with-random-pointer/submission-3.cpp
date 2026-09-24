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
        if(!head) return nullptr;
        Node* curr = head;
        while(curr){
            Node* x = new Node(0);
            x->val = curr->val;
            x->next = curr->next;
            curr->next = x;
            curr = x->next;
        }

        curr = head;
        while(curr && curr->next){
            Node* copy = curr->next;
            if(curr->random){
                copy->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head->next;
        while(curr && curr->next){
            curr->next = curr->next->next;
            curr = curr->next;
        }
        return head->next;
    }
};
