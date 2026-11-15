// class Solution {
// public:
//     int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
//         int count = 0;
//         for(int i = 0; i<arr1.size(); i++)
//         {
//             bool include = true;
//             for(int j = 0; j<arr2.size(); j++)
//             {
//                 int dist = abs(arr1[i]-arr2[j]);
//                 if(dist<=d)
//                 {
//                     include = false;
//                     break;
//                 }
//             }
//             if(include)
//                 count++;
//         }
//         return count;
//     }
// };


class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int count = 0;
        for(int x : arr1)
        {
            int low = 0;
            int high = arr2.size();
            bool include = true;
            // |a-b|<=d for invalid condition
            // is equivalent to a-d <= b <= a+d
            // find whether any element of sorted arr2 lies in the range [x-d, x+d]
            while(low<=high)
            {
                int mid = low + (high - low)/2;
                if(arr2[mid]>=x-d && arr2[mid]<=x+d)
                {
                    include = false;
                    break;
                }
                else if(arr2[mid]<x-d)
                    low = mid+1;
                else
                    high = mid-1;
            }
            if(include)
                count++;
        }
        return count;
    }
};