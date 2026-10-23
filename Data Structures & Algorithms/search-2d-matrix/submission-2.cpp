class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low_row = 0;
        int high_row = matrix.size() - 1;
        while (low_row <= high_row) {
            int middle_row = low_row + (high_row - low_row)/2;
            std::vector<int> vect = matrix[middle_row];
            if (target < vect[0]) {
                high_row = middle_row - 1;
            } else if (target > vect.back()) {
                low_row = middle_row + 1;
            } else {
                int l = 0;
                int r = vect.size() - 1;
                while (l <= r) {
                    int m = l + (r-l)/2;
                    if (target < vect[m]) {
                        r = m-1;
                    } else if (target > vect[m]) {
                        l = m+1;
                    } else {
                        return true;
                    }
                }
                break;
            }
        }
        return false;
    }
};
