class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(), res = -1001;
        for (int i = n - 1; i >= 0; i--) {
            energy[i] += (i + k) < n ? energy[i + k]: 0;
            res = max(res, energy[i]);
        }
        return res;
    }
};