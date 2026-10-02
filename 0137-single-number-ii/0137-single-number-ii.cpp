class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
         // Check every bit position
        for(int bit = 0; bit<32; bit++)
        {
            int count = 0;
            // Count how many numbers have this bit set(1)
            for(int num : nums)
            {
                if(num & (1<<bit))
                    count++;
            }
            // Remove groups of 3
            if(count%3)
                ans = ans | (1<<bit);
        }
        return ans;
    }
};