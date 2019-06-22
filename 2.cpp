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
        ListNode *answer = NULL;
        ListNode *current = NULL;
        
        while (l1!=NULL || l2!=NULL || carry > 0) {
            int lhs = (l1==NULL) ? 0 : l1->val;
            int rhs = (l2==NULL) ? 0 : l2->val;
            int sum = lhs+rhs+carry;
            
            carry = sum / 10;
            sum = sum % 10;
            
            if (current != NULL) {
                current->next = new ListNode(sum);
                current = current->next;
            }
            else {
                answer = new ListNode(sum);
                current = answer;
            }
            
            if (l1!=NULL) {
                l1 = l1->next;
            }
            if (l2!=NULL) {
                l2 = l2->next;
            }
        }
        
        return answer;
    }
};

/* Add until both list pointers become NULL and no carry remains */