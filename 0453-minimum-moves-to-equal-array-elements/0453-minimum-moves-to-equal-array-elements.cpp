class Solution {
public:
    int minMoves(vector<int>& nums) {
        // IDEA : Increment n-1 elements by 1 Equivalent to decrementing 1 element by 1 (same relative differences)
        int mini = INT_MAX;
        for(int num : nums)
            mini = min(mini,num);
        int ans = 0;
        for(int num : nums)
            ans +=num-mini; //Bring every element down to the minimum
        return ans;
    }
};