class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long sum = 0;
        for(auto gift : gifts) {
            sum += gift;
        }

        while(k--) {
            long long curr = pq.top();
            pq.pop();
            long long sqCurr = sqrt(curr);

            sum = sum - curr + sqCurr;
            pq.push(sqCurr);
        }

        return sum;
    }
};