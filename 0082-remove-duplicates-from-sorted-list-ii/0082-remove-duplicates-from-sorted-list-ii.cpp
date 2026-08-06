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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int>freq;
        ListNode* temp = head;
        while(temp)
        {
            freq[temp->val]++;
            temp=temp->next;
        }
        ListNode dummy(0);
        ListNode* tail= &dummy;
        temp=head;
        while(temp)
        {
            if(freq[temp->val]==1)
            {
                tail->next = temp;
                tail=tail->next;
            }
            temp=temp->next;
        }
        tail->next=nullptr;
        return dummy.next;
    }
};


// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         unordered_map<int,int>freq;
//         ListNode* temp = head;
//         while(temp)
//         {
//             freq[temp->val]++;
//             temp=temp->next;
//         }
//         ListNode dummy(0);
//         ListNode* tail= &dummy;
//         temp=head;
//         while(temp)
//         {
//             if(freq[temp->val]==1)
//             {
//                 tail->next = new ListNode(temp->val);
//                 tail=tail->next;
//             }
//             temp=temp->next;
//         }
//         return dummy.next;
//     }
// };