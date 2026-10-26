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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return true;
        }
        std::sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) {
            if (i1.start != i2.start) {
                return i1.start < i2.start;
            }
            return i1.end < i2.end;
        });
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i].end > intervals[i+1].start) {
                return false;
            }
        }
        return true;
    }
};
