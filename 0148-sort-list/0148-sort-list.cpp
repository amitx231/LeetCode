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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr)
            return head;
        vector<ListNode*>nodes;
        ListNode* temp=head;
        while(temp)
        {
            nodes.push_back(temp);
            temp=temp->next;
        }
        sort(nodes.begin(),nodes.end(),[](ListNode* a , ListNode* b){
            return a->val < b->val;
        });
        for(int i=0 ; i<nodes.size()-1; i++)
        {
            nodes[i]->next=nodes[i+1];

        }
        nodes.back()->next=nullptr;
        return nodes[0];
    }
};




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