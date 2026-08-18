class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals according to their ending time.
        // Greedy choice: keep the interval that ends earliest.
        sort(intervals.begin(),intervals.end(),
            [](const vector<int>&a , const vector<int>&b)
            {
                return a[1]<b[1];
            }
        );
        int removals = 0;
        // End time of the last interval that we kept.
        int lastEnd = intervals[0][1];
        for(int i =1 ; i<intervals.size() ; i++)
        {
            // If current interval starts before the previous
            // interval ends, they overlap.
            if(intervals[i][0]<lastEnd)
            {
                // Remove the current interval
                removals++;
            }
            else
                // No overlap, so keep the current interval.
                lastEnd = intervals[i][1];
        }
        return removals;

    }
};