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
        ListNode* cnt = head;
        for(int i=1;i<=n;i++){
            cnt=cnt->next;
        }
        ListNode* curr = head;
        if(cnt == nullptr){
            return head->next;
        }
        while(cnt->next){
            curr = curr->next;
            cnt = cnt->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};
