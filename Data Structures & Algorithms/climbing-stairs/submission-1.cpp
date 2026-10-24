class Solution {
    public:
        int climbStairs(int n) {
            std::unordered_map<int, int> memo_;
            if (n <= 0) {
                return 0;
            }
            memo_[0] = 0;
            memo_[1] = 1;
            memo_[2] = 2;
            for (int i = 3; i <= n; ++i) {
                memo_[i] =  memo_[i - 1] + memo_[i - 2];
            }
            return memo_[n];
            
        }

};
