class Solution {
    int getMaxArea(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        int area = arr[0];
        int i = 0;
        
        vector<int> left_smaller(n, -1), right_smaller(n, n);
        while (i < n) {
            while (!s.empty() && s.top() != -1 && arr[s.top()] > arr[i]) {
                right_smaller[s.top()] = i;
                s.pop();
            }
            if (i > 0 && arr[i] == arr[i - 1]) {
                left_smaller[i] = left_smaller[i - 1];
            }
            else {
                left_smaller[i] = s.top();
            }
            s.push(i);
            i++;
        }
        for (int j = 0; j < n; j++) {
            area = max(area, arr[j] * (right_smaller[j] - left_smaller[j] - 1));
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m, 0);

        for(int i=0;i<n;i++) {

            for(int j=0;j<matrix[i].size();j++) {

                if(matrix[i][j] == '0') {
                    dp[j] = 0;
                } 
                else {
                    dp[j] += 1;
                }
            }

            maxArea = max(maxArea, getMaxArea(dp, m));
        }

        return maxArea;
    }
};