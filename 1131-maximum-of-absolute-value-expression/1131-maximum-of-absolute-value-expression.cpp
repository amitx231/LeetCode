class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int max1=INT_MIN, min1=INT_MAX;
        int max2 = INT_MIN, min2=INT_MAX;
        int max3=INT_MIN, min3=INT_MAX;
        int max4 = INT_MIN, min4=INT_MAX;
    
        int n = arr1.size();
        for(int i=0 ; i<n ;i++)
        {
            // ±arr1[i] ± arr2[i] ± i
            int x1 = arr1[i]+arr2[i]+i;
            int x2 = arr1[i]+arr2[i]-i;
            int x3 = arr1[i]-arr2[i]+i;
            int x4 = arr1[i]-arr2[i]-i;

            max1=max(max1,x1);
            min1 = min(min1,x1);
            
            max2=max(max2,x2);
            min2 = min(min2,x2);

            max3=max(max3,x3);
            min3 = min(min3,x3);

            max4=max(max4,x4);
            min4 = min(min4,x4);

        }
        int maxLen = max({max1-min1 , max2-min2 , max3-min3 , max4-min4});
        return maxLen;
    }
};