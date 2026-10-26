class Solution {
public:
    //.     2
    // [1, 3], [[4, 6]]
    // [1, 5], [4, 6]
    // [[1, 5]], 
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int n = intervals.size();
        std::vector<std::vector<int>> new_intervals;
        int index_inserted = 0;    
        for (int i = 0; i < intervals.size(); ++i) {
            if (newInterval[0] <= intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        if (intervals.size() == n) {
            intervals.push_back(newInterval);
        }
       

        
        for (int i = 0; i < intervals.size(); ++i) {
            std::vector<int> interval = intervals[i];
            if (new_intervals.empty() || new_intervals.back()[1] < interval[0]) {
                new_intervals.push_back(interval); 
            } else {
                new_intervals.back()[1] = std::max(new_intervals.back()[1], interval[1]);
            }
        }
        return new_intervals;


        
        
    
    }
};
