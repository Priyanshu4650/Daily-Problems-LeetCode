class Solution {
    bool check(vector<int>& start, int d, int mid) {
        long long prev = start[0];
        for(int i=1;i<start.size();i++) {
            long long next = max(prev + mid, static_cast<long long>(start[i]));
            if(next > start[i] + d) {
                return false;
            }
            prev = next;
        }
        return true;
    }
public:
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(), start.end());

        long long low = 0, high = start.back() - start.front() + d;
        long long ans = 0;

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(check(start, d, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};