class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = INT_MIN;
        for(int pile : piles)
            high = max(high, pile);
        int ans = high;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            long long hours = 0;
            for(int pile : piles)
                hours+=(pile + mid - 1)/mid;
            // If total hours <= h, speed is sufficient.... Try a smaller speed: high = mid - 1
            if(hours<=h)
            {
                ans = mid;
                high = mid-1;
            }
            //Otherwise, speed is insufficient. Increase it: low = mid + 1
            else
                low = mid + 1;
        }
        return ans;
    }
};