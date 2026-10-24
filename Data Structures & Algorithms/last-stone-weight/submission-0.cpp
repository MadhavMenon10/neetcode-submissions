class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq(stones.begin(), stones.end());
        while (!(pq.size() <= 1)) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(std::abs(y-x));
            }
        }
        if (pq.size() == 1) {
            return pq.top();
        }
        return 0;
    }
};
