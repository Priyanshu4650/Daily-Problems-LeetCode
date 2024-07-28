class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& A) {
        long long n = A.size();
        vector<long long> f(n + 2);
        for (long long i = 0; i < n + 2; i++) {
            f[i] = i;
        }

        for (long long i = 0; i < n; i++) {
            long long x = A[i][0];
            long long y = A[i][1];
            long long r = A[i][2];

            if (x - r <= 0 || y + r >= Y) {
                f[find(f, n)] = find(f, i);
            }
            if (x + r >= X || y - r <= 0) {
                f[find(f, n + 1)] = find(f, i);
            }

            for (long long j = 0; j < i; j++) {
                long long x2 = A[j][0];
                long long y2 = A[j][1];
                long long r2 = A[j][2];

                if ((x - x2) * (x - x2) + (y - y2) * (y - y2) <= (r + r2) * (r + r2)) {
                    f[find(f, i)] = find(f, j);
                }
            }
        }

        return find(f, n) != find(f, n + 1);
    }

private:
    long long find(vector<long long>& f, long long i) {
        if (f[i] != i) {
            f[i] = find(f, f[i]);
        }
        return f[i];
    }
};