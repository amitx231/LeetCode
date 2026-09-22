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
// class Solution {
// public:
//     int getLength(ListNode* head) {
//         int count = 0;
//         while (head != nullptr) {
//             count++;
//             head = head->next;
//         }
//         return count;
//     }

//     bool isPalindrome(ListNode* head) {
//         if(head==nullptr || head->next ==nullptr)
//             return true;
//         int n = getLength(head);
//         ListNode* temp = head;
//         stack<int>s;
//         int count = 0;
//         while(temp && count<n/2)
//         {
//             s.push(temp->val);
//             temp=temp->next;
//             count++;
//         }
//         if(n%2)
//             temp=temp->next;
//         while(!s.empty())
//         {
//             if(s.top()==temp->val)
//             {
//                 s.pop();
//                 temp=temp->next;
//             }
//             else 
//                 return false;
                
//         }
//         return true;


//     }
// };


class Solution {
public:

    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next ==nullptr)
            return true;
        
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        // if odd length, skip middle
        if(fast)
            slow=slow->next;

        // reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while(curr)
        {
            ListNode* nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        // prev = head of reversed second half
        ListNode* first = head;
        ListNode* second = prev;
        while(second!=nullptr)
        {
            if(first->val!=second->val)
                return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};