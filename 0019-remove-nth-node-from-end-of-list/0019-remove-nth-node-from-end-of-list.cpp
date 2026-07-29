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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int N = 0;
        while(temp!=nullptr)
        {
            N++;
            temp=temp->next;
        }
        int node_from_start=N-n+1;
        // Delete head node
        // node_from_start = N - n + 1
        //         = 3 - 3 + 1
        //         = 1
        if(node_from_start == 1)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        temp=head;
        for(int i=1;i<node_from_start-1;i++)
        {
            temp=temp->next;
        }
        ListNode* del=temp->next;
        temp->next=del->next;
        delete del;
        return head;
    }
};