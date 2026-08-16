// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<int>freq;
//         for(int i=0 ; i<nums.size(); i++)
//         {
//             int count =0;
//             for(int j=i+1;j<nums.size(); j++)
//             {
//                 if(nums[j]<nums[i])
//                     count++;
//             }
//             freq.push_back(count);
//         }
//         return freq;
//     }
// };



class Solution {
public:
    vector<int> ans;
    void mergeSort(vector<pair<int,int>>& nums , int low , int high)
    {
        if(low>=high)
            return;
        int mid = low + (high-low)/2;
        mergeSort(nums, low , mid);
        mergeSort(nums, mid+1 , high);
        merge(nums,low , mid , high);
    }
    void merge(vector<pair<int,int>>& nums , int low , int mid , int high)
    {
        vector<pair<int,int>>temp;
        int i= low;
        int j= mid+1;
        // Number of right-half elements smaller
        // than the current left element
        int smallerRight= 0;
        while(i<=mid && j<=high)
        {
            if(nums[j].first<nums[i].first)
            {
                temp.push_back(nums[j]);
                j++;
                smallerRight++;
            }
            else
            {
                ans[nums[i].second]+=smallerRight;
                temp.push_back(nums[i]);
                i++;
            }
        }
        // Remaining left elements
        while(i<=mid)
        {
            ans[nums[i].second]+=smallerRight;
            temp.push_back(nums[i]);
            i++;
        }
        // Remaining right elements
        while(j<=high)
        {
            temp.push_back(nums[j]);
            j++;
        }
        // Copy merged result back
        for(int k=0 ; k<temp.size(); k++)
        {
            nums[low+k]=temp[k];
        }
    }


    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n,0);
        vector<pair<int , int >> indexed;
        // Store value + original index
        for(int i =0 ; i<n ; i++)
        {
            indexed.push_back({nums[i],i});

        }
        mergeSort(indexed , 0 , n-1);
        return ans;
    }
};