/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* a = headA;
//         // Traverse every node of List A
//         while (a)
//         {
//             // For every node in List A,start traversing List B from its beginning
//             ListNode* b = headB;

//             while (b)
//             {
//                 // Compare the actual node addresses
//                 // If both pointers point to the same node,we have found the intersection
//                 if (a == b)
//                     return a;
//                 b = b->next;
//             }
//             a = a->next;
//         }
//         // If no common node was found,the two lists do not intersect
//         return nullptr;
//     }
// };



class Solution {
public:
    //Two pointer approach ... with T.C = O(m+n) , S.C = O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        // Continue until both pointers point to the same node.
        // both pointer travel a+b distance 
        while(a!=b)
        {
            //Move A forward. If A finishes, start walking through B.
            if(a==nullptr)
                a=headB;
            else
                a=a->next;
            //Move B forward. If B finishes, start walking through A.
            if(b==nullptr)
                b=headA;
            else
                b=b->next;
        }
        return a;
    }
};