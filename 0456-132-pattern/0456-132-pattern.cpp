// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0; i<n; i++)
//         {
//             for(int j = i+1; j<n; j++)
//             {
//                 for(int k = j+1; k<n; k++)
//                 {
//                     if(nums[i]<nums[k] && nums[k]<nums[j])
//                         return true;
//                 }
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int nums3 = INT_MIN;
        stack<int>s;
        for(int i = n-1; i>=0; i--)
        {
            if(nums3 > nums[i])
                return true;
            while(!s.empty() && s.top()<nums[i])
            {
                nums3 = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};