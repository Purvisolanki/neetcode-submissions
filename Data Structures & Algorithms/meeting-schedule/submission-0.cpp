class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        // Sort by start time
        sort(intervals.begin(), intervals.end(),
             [](Interval& a, Interval& b) {
                 return a.start < b.start;
             });

        // Check adjacent meetings
        for (int i = 1; i < intervals.size(); i++) {

            int previous_end = intervals[i - 1].end;
            int current_start = intervals[i].start;

            // Conflict
            if (current_start < previous_end) {
                return false;
            }
        }

        return true;
    }
};