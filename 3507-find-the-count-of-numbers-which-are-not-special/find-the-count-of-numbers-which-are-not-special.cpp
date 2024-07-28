class Solution {
    vector<bool> SieveOfEratosthenes(int n) {
        // Create a boolean array "prime[0..n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
        vector<bool> prime(n + 1, true);
    
        for (int p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true) {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which are
                // multiple of p and are less than p^2 are
                // already been marked.
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        
        return prime;
    }
public:
    int nonSpecialCount(int l, int r) {
        vector<bool> specials = SieveOfEratosthenes(sqrt(1e9));
        int cnt = 0;
        for (int i = 2; i <= sqrt(r); i++) {
            if (specials[i]) {
                int square = i * i;
                if (square >= l && square <= r) {
                    cnt++;
                }
            }
        }

        return r - l + 1 - cnt;
    }
};