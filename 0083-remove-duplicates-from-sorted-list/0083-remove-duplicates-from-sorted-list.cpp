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
        if(head==nullptr)
            return head;
        vector<int> nums;
        ListNode* temp = head;
        while(temp)
        {
            if(nums.empty()||nums.back()!=temp->val)
            {
                nums.push_back(temp->val);
            }
            temp=temp->next;
        }
        ListNode dummy(0);
        ListNode* tail=&dummy;
        for(int x : nums)
        {
            tail->next=new ListNode(x);
            tail=tail->next;
        }
        return dummy.next;
    }
};