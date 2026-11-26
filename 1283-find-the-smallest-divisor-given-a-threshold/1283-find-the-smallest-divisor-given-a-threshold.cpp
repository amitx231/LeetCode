class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = INT_MIN;
        for(int num : nums)
            high = max(high, num);
        // 875 KOKO problem is same
        int ans = high;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            long long divisor = 0;
            for(int num : nums)
                divisor += (num + mid - 1)/mid;
            if(divisor<=threshold)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid +1;
        }
        return ans;
    }
};