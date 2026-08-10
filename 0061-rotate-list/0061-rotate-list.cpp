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
    // T.C.=O(n) and S.C = O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
            return head;
        int n = 1 ;
        ListNode* tail = head;
        // Find length of list and oldTail
        while(tail->next)
        {
            n++;
            tail=tail->next;
        }
        // Reduce unnecessary rotations
        k=k%n;
        if(k==0)
            return head;
        // Find new tail
        ListNode* newTail = head;
        for(int i=1 ; i<n-k ; i++)
        {
            newTail = newTail->next;
        }
        // New head is after new tail
        ListNode* newHead = newTail->next;
        // Break the list
        newTail->next = nullptr;
        // Connect old tail to old head
        tail->next = head;
        return newHead;

    }
};