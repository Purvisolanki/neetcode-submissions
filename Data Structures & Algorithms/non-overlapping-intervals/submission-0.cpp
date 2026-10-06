class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int count = 0;

        int last_end = intervals[0][1];

        for (int i = 1; i < n; i++) {

            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            if (curr_start >= last_end) {
                // No overlap
                last_end = curr_end;
            }
            else {
                // Overlap -> remove current interval
                count++;
            }
        }

        return count;
    }
};