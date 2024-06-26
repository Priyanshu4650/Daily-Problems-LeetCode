class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0), res(n, 0);

        // left[0] = nums[0];
        for(int i=1;i<n;i++) {
            left[i] += left[i-1] + nums[i-1];
        }
        for(int i=0;i<n;i++) {
            cout << left[i] << " ";
        }
        cout << endl;
        // right[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) {
            right[i] += right[i+1] + nums[i+1];
        }
        for(int i=0;i<n;i++) {
            cout << right[i] << " ";
        }
        cout << endl;

        for(int i=0;i<n;i++) {
            res[i] = abs(left[i] - right[i]);
        }

        return res;
    }
};