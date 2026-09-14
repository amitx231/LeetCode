class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pse(n); // previous smaller element index
        vector<int>nse(n); //next smaller element index
        stack<int>s;
        //pse
        for(int i=0; i<n ;  i++)
        {
            int curr  = i;
            while(!s.empty() && heights[curr]<=heights[s.top()])
                s.pop();
            if(s.empty())
                pse[i]=-1;
            else 
                pse[i]=s.top();
            s.push(curr);
        }
         //clear stack
        while(!s.empty())
            s.pop();

        //nse
        for(int i = n-1 ; i>=0 ; i--)
        {
            int curr = i;
            while(!s.empty() && heights[curr]<=heights[s.top()])
                s.pop();
            if(s.empty())
                nse[i]=n; //-1
            else 
                nse[i]=s.top();
            s.push(curr);
        }

        int maxArea = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            int width = nse[i]-pse[i]-1; // width =  right boudary - left boundary -1
            int area = heights[i]*width;
            maxArea= max(maxArea , area);
        }
        return maxArea;
    }
};