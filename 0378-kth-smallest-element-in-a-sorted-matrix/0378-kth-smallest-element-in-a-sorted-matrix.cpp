class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int>ans;
        // make a 1D array and push all the matrix element(total = n^2) in this
        for(int i = 0 ; i<n; i++)
        {
            for(int j= 0; j<n; j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        //then sort array/vector
        sort(ans.begin(),ans.end());
        return ans[k-1];
        // T.C = n^2.log(n^2)
        // S.C. = n^2
    }
};