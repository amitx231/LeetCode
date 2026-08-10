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
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* i=list1;
//         ListNode* j = list2;
//         ListNode dummy(0);
//         ListNode* tail = &dummy;
//         while(i!=nullptr && j!=nullptr)
//         {
//             if(i->val<=j->val)
//             {
//                 // tail->next=new ListNode(i->val);
//                 tail->next=i;
//                 tail=tail->next;
//                 i=i->next;
//             }
//             else{
//                 // tail->next=new ListNode(j->val);
//                 tail->next=j;
//                 tail=tail->next;
//                 j=j->next;
//             }
//         }
//         while(i!=nullptr)
//         {
//             // tail->next=new ListNode(i->val);
//             tail->next=i;
//             tail=tail->next;
//             i=i->next;
//         }
//         while(j!=nullptr)
//         {
//             // tail->next = new ListNode(j->val);
//             tail->next = j;
//             tail = tail->next;
//             j=j->next;
//         }
        
//         return dummy.next;
//     }
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.empty())
//             return nullptr;
//         ListNode* ans = lists[0];
//         for(int i=1 ; i<lists.size() ; i++)
//         {
//             ans=mergeTwoLists(ans, lists[i]);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* i=list1;
        ListNode* j = list2;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(i!=nullptr && j!=nullptr)
        {
            if(i->val<=j->val)
            {
                // tail->next=new ListNode(i->val);
                tail->next=i;
                tail=tail->next;
                i=i->next;
            }
            else{
                // tail->next=new ListNode(j->val);
                tail->next=j;
                tail=tail->next;
                j=j->next;
            }
        }
        while(i!=nullptr)
        {
            // tail->next=new ListNode(i->val);
            tail->next=i;
            tail=tail->next;
            i=i->next;
        }
        while(j!=nullptr)
        {
            // tail->next = new ListNode(j->val);
            tail->next = j;
            tail = tail->next;
            j=j->next;
        }
        
        return dummy.next;
    }
    // Divide the lists into smaller groups and merge them recursively
    ListNode* divide(vector<ListNode*>& lists , int left , int right)
    {
        // Only one list remains
        if(left==right)
            return lists[left];
        int mid = left + (right - left)/2;
        // Divide into two halves
        ListNode* l1 = divide(lists, left , mid);
        ListNode* l2 = divide(lists, mid+1 , right);
        // Merge the two sorted halves
        return mergeTwoLists(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        // Divide all lists and merge them
        return divide(lists , 0 , lists.size()-1);
    }
};