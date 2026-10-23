class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());
        int res = high;
        int k;
        while (low <= high) {
            k = low + (high - low)/2;
            int hours = 0;
            for (int i = 0; i < piles.size(); ++i) {
                hours += std::ceil(static_cast<double>(piles[i])/k);
            }
            if (hours > h) {
                low = k + 1;
            }
            if (hours <= h) {
                res = std::min(k, res);
                high = k - 1;
            }
        }
        return res;
    }
};
