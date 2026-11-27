class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int num : nums)
        {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        for(int num : nums)
        {
            if(num!=mini && num!=maxi)
                return num;
        }
        return -1;
    }
};