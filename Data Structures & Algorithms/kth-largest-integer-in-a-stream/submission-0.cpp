class KthLargest {
    public:
        KthLargest(int k, vector<int>& nums): pq_(nums.begin(), nums.end()), k_(k) {}
        
        int add(int val) {
            pq_.push(val);
            std::vector<int> vals;
            int num_to_return = 0;
            for (int i = 0; i < k_; ++i) {
                int num = pq_.top();
                pq_.pop();
                if (i == k_-1) {
                    num_to_return = num;
                }
                vals.push_back(num);
            }
            for (auto num : vals) {
                pq_.push(num);
            } 
            return num_to_return;
        }
    private: 
        std::priority_queue<int> pq_;
        int k_;
};
