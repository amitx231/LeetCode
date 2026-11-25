class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>s;
        s.push(asteroids[n-1]);
        for(int i = n-2; i>=0; i--)
        {
            int curr = asteroids[i];
            bool alive = true;
            while(!s.empty() && s.top() < 0 && curr > 0)
            {
                //Pop stack top; continue checking
                if(abs(s.top())<abs(curr))
                    s.pop();
                //Pop stack top; current also explodes
                else if(abs(s.top())==abs(curr))
                {
                    s.pop();
                    alive = false;
                    break;
                }
                //Current explodes
                else
                {
                    alive = false;
                    break;
                }
            }
            if(alive)
                s.push(curr);
        }
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};