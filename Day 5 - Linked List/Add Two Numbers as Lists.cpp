Add Two Numbers as Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    int carry = 0;
    while(A!=NULL || B!=NULL || carry) {
        int sum = 0;
        if(A != NULL) {
            sum = sum + A->val;
            A = A->next;
        }
        if(B != NULL) {
            sum = sum + B->val;
            B = B->next;
        }
        sum = sum + carry;
        carry = sum / 10;
        ListNode* node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}
