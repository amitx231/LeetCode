class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        for(int i =0 ; i<n ; i++){
            //First Element
            if(i==0)
            {
                if(nums[i]>nums[i+1])
                return i;
            } 
            //Last Element 
            else if(i==n-1) 
            {
                if(nums[i-1]<nums[i])
                    return i;
            } 
            //Middle Element
            else
            {
                if(nums[i-1]<nums[i] && nums[i]>nums[i+1])
                    return i;
            }
        }
        return -1;
    }
};