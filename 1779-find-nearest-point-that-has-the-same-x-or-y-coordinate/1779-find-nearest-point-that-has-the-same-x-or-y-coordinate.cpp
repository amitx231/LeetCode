class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int mini =  INT_MAX;
        int ans = -1;
        for(int i = 0; i<points.size(); i++)
        {
            int a = points[i][0];
            int b = points[i][1];
            if(a==x || b==y)
            {
                int dist = abs(a-x) + abs(b-y);
                if(dist<mini)
                {
                    mini = dist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};