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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        // Traverse every node of List A
        while (a)
        {
            // For every node in List A,start traversing List B from its beginning
            ListNode* b = headB;

            while (b)
            {
                // Compare the actual node addresses
                // If both pointers point to the same node,we have found the intersection
                if (a == b)
                    return a;
                b = b->next;
            }
            a = a->next;
        }
        // If no common node was found,the two lists do not intersect
        return nullptr;
    }
};