/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A == NULL) {
        return B;
    }
    if(B == NULL) {
        return A;
    }
    ListNode *temp;
    if(A->val <= B->val) {
        temp = A;
        temp->next = mergeTwoLists(A->next, B);
    } else {
        temp = B;
        temp->next = mergeTwoLists(A, B->next);
    }
    return temp;
}
