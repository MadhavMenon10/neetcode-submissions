class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int max_area = 0;
        while (l < r) {
            int area = (r-l) * std::min(heights[l], heights[r]);
            max_area = std::max(max_area, area);
            if (heights[r] <= heights[l]) {
                --r;
            } else {
                ++l;
            }
        }
        return max_area;
    }
};
