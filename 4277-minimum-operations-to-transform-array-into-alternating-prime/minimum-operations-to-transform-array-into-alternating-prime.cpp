class Solution {
public:
    inline static const int n = 100004;
    inline static int sieve[n];
    inline static int init = []() {
        sieve[0] = sieve[1] = 1;

        for (int i = 2; i <= 316; i++)
            if (!sieve[i])
                for (int j = i * i; j < n; j += i)
                    sieve[j] = 1;

        return 0;
    }();

    int minOperations(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = nums[i];
            if (i & 1)
                while (!sieve[j++])
                    res++;
            else
                while (sieve[j++])
                    res++;
        }

        return res;
    }
};