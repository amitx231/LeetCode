class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>range;
        if(n==0)
            return range;
        int start = nums[0];
        for(int i = 1; i<n; i++)
        {
            if(nums[i]!=nums[i-1]+1)
            {
                if(start == nums[i-1])
                    range.push_back(to_string(start));
                else
                    range.push_back(to_string(start)+"->"+to_string(nums[i-1]));
                start = nums[i];
            }
        }

        // processing the last range
        if(start==nums[n-1])
            range.push_back(to_string(start));
        else
            range.push_back(to_string(start)+"->"+to_string(nums[n-1]));
        return range;
    }
};