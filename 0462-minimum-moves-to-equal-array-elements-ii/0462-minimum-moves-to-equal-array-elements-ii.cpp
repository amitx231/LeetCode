class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int median = n/2;   //median minimizes the sum of absolute differences.... So we are calcuting from median
        int ans = 0;
        for(int num : nums)
            ans += abs(num-nums[median]);

        return ans;
    }
};