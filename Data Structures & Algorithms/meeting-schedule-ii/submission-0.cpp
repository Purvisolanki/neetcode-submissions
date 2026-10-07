class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        if (intervals.empty()) {
            return 0;
        }

        // Sort meetings by start time
        sort(intervals.begin(), intervals.end(),
             [](Interval& a, Interval& b) {
                 return a.start < b.start;
             });

        // Min-heap: earliest ending meeting at top
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto& meeting : intervals) {

            // If a room is free, reuse it 
            if (!minHeap.empty() && meeting.start >= minHeap.top()) {
                minHeap.pop();
            }

            // Occupy a room until this meeting ends
            minHeap.push(meeting.end);
        }

        return minHeap.size();
    }
};