class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1); // dp[i] = minimum cost required to reach step i
        dp[0]=0;         // Starting point: step 0 has no cost
        for(int i = 1; i<=n; i++)
        {
            // 1st way if jump from (i-1) to i
            dp[i]=dp[i-1] + costs[i-1] + 1;
            //2nd way if jump from (i-2) to i
            if(i>=2)
                dp[i]=min(dp[i], dp[i-2] + costs[i-1] + 4);
            //3rd way if jump from (i-3) to i
            if(i>=3)
                dp[i]=min(dp[i],dp[i-3] + costs[i-1] + 9);
        }
        return dp[n];
    }
};