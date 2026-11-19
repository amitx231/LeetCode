class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>>cars;
        // Store position and time to reach target
        for(int i=0; i<n; i++)
        {
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        // Sort cars by position (descending)
        sort(cars.rbegin(),cars.rend());

        stack<double>s;
        for(auto car : cars)
        {
            double curr = car.second;
            // A slower or equally timed car forms a new fleet
            if(s.empty() || curr>s.top())
                s.push(curr);
            
        }
        
        return s.size();
    }
};