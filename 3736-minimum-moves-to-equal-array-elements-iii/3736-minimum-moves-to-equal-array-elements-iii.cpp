class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        int ans = 0;
        for(int num : nums)
            maxi = max(num,maxi);
        for(int num : nums)
            ans+=(maxi-num);
        return ans;
    }
};