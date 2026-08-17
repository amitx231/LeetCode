// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1)
//             return 0;
//         for(int i =0 ; i<n ; i++){
//             //First Element
//             if(i==0)
//             {
//                 if(nums[i]>nums[i+1])
//                 return i;
//             } 
//             //Last Element 
//             else if(i==n-1) 
//             {
//                 if(nums[i-1]<nums[i])
//                     return i;
//             } 
//             //Middle Element
//             else
//             {
//                 if(nums[i-1]<nums[i] && nums[i]>nums[i+1])
//                     return i;
//             }
//         }
//         return -1;
//     }
// };



// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         // Traverse until the second-last element
//         for(int i =0 ; i<n-1 ; i++){
//             // If current element is greater than the next element,
//             // then we have found a peak at index i.
//             if(nums[i]>nums[i+1])
//                 return i;
//         }
//         // If the array is continuously increasing,
//         // the last element will be the peak.
//         return n-1;
//     }
// };


class Solution {
public:
    //We will shrink the search range until exactly one possible peak index remains.
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low=0 , high = n-1;
        while(low<high)
        {
            int mid = low + (high - low)/2;
            //We are going uphill.Therefore, there must be a peak somewhere on the right side.
            if(nums[mid]<nums[mid+1])
                low = mid+1;
            //We are going downhill.Therefore, a peak exists at mid or somewhere on the left side.
            else 
                high=mid;
        }
        return low;
    }
};