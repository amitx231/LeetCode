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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode * tail = &dummy;
        int carry =0;
        while(l1 || l2 || carry)
        {
            
            int temp = carry;

            if(l1)
            {
                temp += l1->val;
                l1 = l1->next;
            }

            if(l2)
            {
                temp += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(temp % 10);
            tail=tail->next;
            carry = temp / 10;
        }
        return dummy.next;
    }
};


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         list<int>sum;
//         int carry =0;
//         while(l1 || l2 || carry)
//         {
            
//             int temp = carry;

//             if(l1)
//             {
//                 temp += l1->val;
//                 l1 = l1->next;
//             }

//             if(l2)
//             {
//                 temp += l2->val;
//                 l2 = l2->next;
//             }
//             sum.push_back(temp % 10);
//             carry = temp / 10;
//         }
//         ListNode* head = nullptr;
//         ListNode* tail = nullptr;

//         for (int x : sum) {
//             ListNode* newNode = new ListNode(x);

//             if (head == nullptr) {
//                 head = newNode;
//                 tail = newNode;
//             } else {
//                 tail->next = newNode;
//                 tail = newNode;
//             }
//         }

//         return head;
//     }
// };





// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         list<int>sum;
//         bool carry =false;
//         int temp;
//         while(l1!=nullptr && l2!=nullptr)
//         {
            
//             if(carry)
//                 temp=l1->val+l2->val+1;
//             else
//                 temp=l1->val+l2->val;
//             sum.push_back(temp%10);
//             if(temp>=10)
//                 carry = true;
//             else 
//                 carry=false;
//             l1=l1->next;
//             l2=l2->next;
//         }
//         while(l1!=nullptr)
//         {
            
//             if(carry)
//                 temp=l1->val+1;
//             else
//                 temp=l1->val;
//             sum.push_back(temp%10);
//             if(temp>=10)
//                 carry = true;
//             else 
//                 carry=false;
//             l1=l1->next;
//         }
//         while(l2!=nullptr)
//         {
//             if(carry)
//                 temp=l2->val+1;
//             else
//                 temp=l2->val;
//             sum.push_back(temp%10);
//             if(temp>=10)
//                 carry = true;
//             else 
//                 carry=false;
//             l2=l2->next;
//         }
//         if(carry)
//             sum.push_back(1);
//         ListNode* head = nullptr;
//         ListNode* tail = nullptr;

//         for (int x : sum) {
//             ListNode* newNode = new ListNode(x);

//             if (head == nullptr) {
//                 head = newNode;
//                 tail = newNode;
//             } else {
//                 tail->next = newNode;
//                 tail = newNode;
//             }
//         }

//         return head;
//     }
// };