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
    ListNode* merge2List(ListNode* l1 , ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if(l1)
        {
            tail->next=l1;
        }
        if(l2)
        {
            tail->next=l2;
        }
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next=nullptr;
        ListNode* left= sortList(head);
        ListNode* right = sortList(mid);
        return merge2List(left,right);
    }
};





// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if(head==nullptr)
//             return head;
//         vector<ListNode*>nodes;
//         ListNode* temp=head;
//         while(temp)
//         {
//             nodes.push_back(temp);
//             temp=temp->next;
//         }
//         sort(nodes.begin(),nodes.end(),[](ListNode* a , ListNode* b){
//             return a->val < b->val;
//         });
//         for(int i=0 ; i<nodes.size()-1; i++)
//         {
//             nodes[i]->next=nodes[i+1];

//         }
//         nodes.back()->next=nullptr;
//         return nodes[0];
//     }
// };




// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if(head==nullptr)
//             return head;
//         vector<int>nums;
//         ListNode* temp=head;
//         while(temp)
//         {
//             nums.push_back(temp->val);
//             temp=temp->next;
//         }
//         sort(nums.begin(),nums.end());
//         temp=head;
//         int i=0;
//         while(temp)
//         {
//             temp->val=nums[i++];
//             temp=temp->next;
//         }
//         return head;
//     }
// };