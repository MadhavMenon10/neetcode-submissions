class TimeMap {
    public:
        TimeMap() = default;
        
        void set(string key, string value, int timestamp) {
            store_[key].push_back({timestamp, value});
        }
        
        string get(string key, int timestamp) {
            auto it = store_.find(key);
            if (it == store_.end()) {
                return "";
            }
            int l = 0;
            int r = it->second.size() - 1;
            int max_idx = -1;
            while (l <= r) {
                int m = l + (r-l)/2;
                if (it->second[m].first > timestamp) {
                    r = m - 1;
                } else {
                    max_idx = m;
                    l = m+1;
                }
            }
            if (max_idx == -1) {
                return "";
            }
            return it->second[max_idx].second;
        }
    private:
        std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store_;
};
