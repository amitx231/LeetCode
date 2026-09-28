class Solution {
public:
    int possiblity(vector<int>& nums , int start , int end)
    {
        int prev2 = 0 ;
        int prev1 = 0 ;

        for(int i = start; i<=end; i++)
        {
            int curr = max(prev1, nums[i]+prev2);
            prev2= prev1;
            prev1 = curr;
        }
        return prev1;

    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        
        //since now house are arrangend in a circle then we will take two possiblities to rob ...

        //case 1 : dont rob the last house
        int case1 = possiblity(nums, 0, n-2);
        //case 2 : dont rob the first house
        int case2 = possiblity(nums, 1, n-1);
        // better possiblity will be the ansewer
        return max(case1, case2);
    }

};