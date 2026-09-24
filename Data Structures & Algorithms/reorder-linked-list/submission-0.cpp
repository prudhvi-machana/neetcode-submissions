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
        map<int, ListNode* > mp;
        int cnt = 0;
        while(head){
            mp[cnt] = head;
            head = head->next;
            cnt++;
        }
        int tmp = 0;
        while(tmp < cnt/2){
            ListNode* n1 = mp[tmp];
            ListNode* n2 = mp[cnt-tmp-1];
            n2->next = n1->next;
            n1->next = n2;
            tmp++;
        }
        mp[cnt/2]->next = nullptr;
    }
};
