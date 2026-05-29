/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> events;

        for(auto &it : intervals) {
            events.push_back({it.start, 1});
            events.push_back({it.end, -1});
        }
//sort nhi krna to events ko vector ki jagah ordered map l sakte
        sort(events.begin(), events.end());


        int overlaps = 0;
        int maxOverlaps = 0;

        for(auto &it : events){
            overlaps += it.second;

            maxOverlaps = max(maxOverlaps,overlaps);
        }
        return maxOverlaps;
    }
};
