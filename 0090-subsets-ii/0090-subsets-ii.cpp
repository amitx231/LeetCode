class Solution {
public:
    void giveSubsets(vector<int>&nums, vector<vector<int>>&ans, vector<int>&subset, int i)
    {
        if(i==nums.size())
        {
            ans.push_back(subset);
            return;
        }

        // Choice YES: Include current element
        subset.push_back(nums[i]);
        giveSubsets(nums,ans,subset,i+1);

        //backtracking
        subset.pop_back();

        // Choice NO: Skip current element and its duplicates
        while(i+1<nums.size() && nums[i]==nums[i+1])
            i++;
        giveSubsets(nums, ans, subset, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        sort(nums.begin(),nums.end());

        giveSubsets(nums,ans,subset,0);
        return ans;
    }
};