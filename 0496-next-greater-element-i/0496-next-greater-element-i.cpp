// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums2.size();
//         vector<int>nge(n,0);
//         stack<int>s;
//         // Find NGE for every element of nums2
//         nge[n-1]=-1;
//         s.push(nums2[n-1]);
//         for(int i = n-2 ; i>=0 ; i--)
//         {
//             int curr = nums2[i];
//             while(!s.empty() && curr>=s.top())
//                 s.pop();
//             if(s.empty())
//                 nge[i]=-1;
//             else
//                 nge[i]=s.top();
//             s.push(curr);
//         }
//         // Find answer for every element of nums1
//         vector<int>ans;
//         for(int x : nums1)
//         {
//             int pos = -1;
//             for(int i =0 ; i<nums2.size() ; i++)
//             {
//                 if(nums2[i]==x)
//                 {
//                     pos=i;
//                     break;
//                 }
//             }
//             ans.push_back(nge[pos]);
//         }
//         return ans;
//     }

// };


// Finding in T.C. = O(nums1.length + nums2.length) using unordered map
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>mp;
        stack<int>s;
        // Find NGE for every element of nums2
        for(int i = n-1 ; i>=0 ; i--)
        {
            int curr = nums2[i];
            while(!s.empty() && curr>=s.top())
                s.pop();
            if(s.empty())
                mp[curr]=-1;
            else
                mp[curr]=s.top();
            s.push(curr);
        }
        // Find answer for every element of nums1
        vector<int>ans;
        for(int x : nums1)
        {
            ans.push_back(mp[x]);
        }
        return ans;
    }


};