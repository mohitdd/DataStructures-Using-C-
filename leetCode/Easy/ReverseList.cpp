/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* previous = NULL;
        
        while(current != NULL) {
            
            next=current->next;
            current->next = previous;
            previous=current;
            current=next;
        }
        head=previous;
        return head;
    }
    
};