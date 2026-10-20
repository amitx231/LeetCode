class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // unsigned for max_int because when we do (-x) we cant write int_min in integer
        unsigned int x = 0;
        for(int num : nums)
        {
            x^=num;
        }
        //x = unique1 ^ unique2
        //extract a bit where they differ
        unsigned int mask = x & (-x);
        int a = 0;
        int b = 0;
        //split into two groups
        for(int num : nums)
        {
            // non-zero group
            if(num & mask)
                a^=num;
            // zero group
            else
                b^=num;
        }
        return {a,b};
    }
};