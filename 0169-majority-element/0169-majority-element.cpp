// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++)
//         {
//             int count=0;
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(nums[j]==nums[i])
//                     count++;
//             }
//             if(count>nums.size()/2)
//                 return nums[i];
//         }
//         return 0;
//     }
// };




class Solution {
public:
    /*
    For example:[2, 2, 1, 1, 1, 2, 2]
    Count: 2 → 4 and 1 → 3
    Since 2 has more than half the votes, it cannot be completely cancelled by the other elements.
    */
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count=0;
        for(int x : nums)
        {
            //count == 0 → choose new candidate
            if(count==0)
                candidate=x;
            //same candidate → count++
            if(x==candidate)
                count++;
            //different element → count--
            else
                count--;       
        }
        return candidate;
    }
};