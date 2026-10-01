class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        // Put all stones into max heap
        for(int stone : stones) {
            pq.push(stone);
        }

        while(pq.size() > 1) {

            // Get two heaviest stones
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            // If they are different, push the difference
            if(x != y) {
                pq.push(x - y);
            }
        }

        // If one stone remains, return it
        if(pq.empty()) {
            return 0;
        }

        return pq.top();
    }
};