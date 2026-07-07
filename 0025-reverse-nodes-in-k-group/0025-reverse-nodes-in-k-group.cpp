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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;

        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL && count < k){
            temp = temp->next;
            count++;
        }

        if(count < k) return head;

        ListNode* prev = NULL;
        ListNode* next = NULL;
        temp = head;
        while(temp!=NULL && count){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count--;
        }

        if(temp) head->next = reverseKGroup(temp, k);

        return prev;
    }
};