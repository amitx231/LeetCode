class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int x = 0;
        for(int num : nums)
        {
            x^=num;
        }
        unsigned int mask = x & (-x);
        int a = 0;
        int b = 0;
        for(int num : nums)
        {
            if(num & mask)
                a^=num;
            else
                b^=num;
        }
        return {a,b};
    }
};