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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* i=list1;
        ListNode* j = list2;
        list<int> ans;
        while(i!=nullptr && j!=nullptr)
        {
            if(i->val<=j->val)
            {
                ans.push_back(i->val);
                i=i->next;
            }
            else{
                ans.push_back(j->val);
                j=j->next;
            }
        }
        while(i!=nullptr)
        {
            ans.push_back(i->val);
            i=i->next;
        }
        while(j!=nullptr)
        {
            ans.push_back(j->val);
            j=j->next;
        }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for (int x : ans) {
            ListNode* newNode = new ListNode(x);

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        return head;
    }
};