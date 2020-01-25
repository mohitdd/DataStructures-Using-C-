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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode* res = NULL;
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        int sum = 0;
        
        while(l1 != NULL || l2 != NULL) {
            
            int first = l1 ? l1->val : 0;
            int second = l2 ? l2->val :0; 
            
            sum = carry+first+second;
            carry = sum>=10 ? 1 :0;
            sum = sum >=10 ?sum%10 :sum;
            temp = new ListNode(sum);
            
            if(res == NULL) {
                res=temp;
                prev=temp;
            }
            else {
            prev->next=temp;
            prev=temp;        
            }
            
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry >0) {
            temp = new ListNode(carry);
            prev->next=temp;
        }
        return res;
    }
};