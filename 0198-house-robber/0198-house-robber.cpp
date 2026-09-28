// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1)
//             return nums[0];
//         vector<int>dp(n,0);     // dp[i] = maximum money we can rob from houses 0 to i

//         dp[0]=nums[0];          // Only house 0 is available
//         dp[1]=max(nums[0],nums[1]); // For the first two houses, we can rob either house 0 or house 1 but we cannot rob both

//         for(int i = 2; i<n; i++)
//         {
//             // 2 choices ... skip house i OR rob house i
//             dp[i]=max(dp[i-1],
//                         nums[i]+dp[i-2]);
//         }
//         return dp[n-1];
//     }
// };



class Solution {
public:
    int rob(vector<int>& nums) {
        
        int prev2 = 0; // prev2 = dp[i-2]
        int prev1 = 0; // prev1 = dp[i-1]

        for(int money : nums )
        {
            int curr = max(prev1 , money+prev2);
            prev2 = prev1;  // Old prev1 becomes the new prev2
            prev1 = curr;   // Current answer becomes the new prev1
        }
        return prev1;

    }
};