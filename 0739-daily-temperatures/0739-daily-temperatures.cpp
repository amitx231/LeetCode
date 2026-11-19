class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>answer(n,0);
        stack<int>s;
        
        for(int i = n-1; i>=0; i--)
        {
            int curr = temperatures[i];
            // Remove temperatures that are not warmer
            while(!s.empty() && curr>=temperatures[s.top()])
            {
                s.pop();
            }
            // Calculate days until warmer temperature
            if(!s.empty())
                answer[i]=s.top()-i;
            s.push(i); // push current idx
        }
        return answer;
    }
};