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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }

        k %= count;
        if(k==0) return head;

        temp = head;
        count -= (k+1);
        while(count){
            temp = temp->next;
            count--;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;
        temp = newHead;

        while(temp->next!=NULL) temp = temp->next;
        temp->next = head;

        return newHead;
    }
};