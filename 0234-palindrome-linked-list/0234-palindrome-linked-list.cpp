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
    int getLength(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }

    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next ==nullptr)
            return true;
        int n = getLength(head);
        ListNode* temp = head;
        stack<int>s;
        int count = 0;
        while(temp && count<n/2)
        {
            s.push(temp->val);
            temp=temp->next;
            count++;
        }
        if(n%2)
            temp=temp->next;
        while(!s.empty())
        {
            if(s.top()==temp->val)
            {
                s.pop();
                temp=temp->next;
            }
            else 
                return false;
                
        }
        return true;


    }
};