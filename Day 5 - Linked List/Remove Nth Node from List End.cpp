/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* curr = A;
    ListNode* prev;    
    if(A == NULL) {
        return A;
    }
    int size = 0;
    while(curr != NULL) {
        prev = curr;
        curr = curr->next;
        size++;
    }
    if(B == 0){
        B = 1;
    }
    int rem = size-B;
    if(rem <= 0) {
        return A->next;
    }
    curr = A;
    while(rem > 0) {
        prev = curr;
        curr = curr->next;
        rem--;
    }
    prev->next = curr->next;
    return A;
}
