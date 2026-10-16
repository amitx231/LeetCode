class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int n = x^y;
        while(n)
        {
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
};