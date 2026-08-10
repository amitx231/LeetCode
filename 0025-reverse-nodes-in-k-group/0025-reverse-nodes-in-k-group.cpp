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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Store all node pointers
        vector<ListNode*>nodes;
        ListNode* temp = head;
        while(temp)
        {
            nodes.push_back(temp);
            temp=temp->next;
        }
        // Reverse every complete group of k nodes i.e ..... i+k<=nodes.size()
        for(int i=0 ; i+k<=nodes.size() ; i+=k)
        {
            reverse(nodes.begin()+i , nodes.begin()+i+k);
        }
        // Reconnect nodes according to new order
        for(int i=0 ; i<nodes.size()-1 ; i++)
        {
            nodes[i]->next=nodes[i+1];
        }
        // End the linked list
        if(!nodes.empty())
            nodes.back()->next= nullptr;
        return nodes.empty() ? nullptr : nodes[0];
    }
};