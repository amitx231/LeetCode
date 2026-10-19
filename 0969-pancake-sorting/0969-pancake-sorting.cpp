class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>ans;
        int n = arr.size();
        for(int i =  n-1; i>=1; i--)
        {
            int target = i+1;
            int pos = 0;
            for(int j =0 ; j<=i; j++)
            {
                if(arr[j]==target)
                {
                    pos = j;
                    break;
                }
            }
            if(pos==i)
                continue;
            if(pos!=0)
            {
                reverse(arr.begin(),arr.begin()+pos+1);
                ans.push_back(pos+1);
            }
            reverse(arr.begin(),arr.begin()+i+1);
            ans.push_back(i+1);
        }
        return ans;
    }
};