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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // Find meeting point inside the cycle
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                break;
        }
        // if No cycle cycle exists
        if(fast==nullptr || fast->next==nullptr)
            return nullptr;
        slow = head;
        // Find the starting node of the cycle
        if(slow == fast)
            return head;
        else 
        {
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        return nullptr;

    }
};