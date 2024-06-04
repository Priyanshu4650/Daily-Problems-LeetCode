class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        // Merging overlapping intervals
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);
        for (int i = 1; i < meetings.size(); ++i) {
            if (merged.back()[1] >= meetings[i][0]) {
                // Overlapping intervals, merge them
                merged.back()[1] = max(merged.back()[1], meetings[i][1]);
            } else {
                // Non-overlapping interval, add it to merged
                merged.push_back(meetings[i]);
            }
        }
        
        // Counting days between merged intervals
        int count = merged[0][0] - 1;
        for (int i = 1; i < merged.size(); ++i) {
            count += merged[i][0] - merged[i - 1][1] - 1;
        }
        
        // Add remaining days after the last merged interval
        count += max(0, days - merged.back()[1]);
        
        return count;
    }
};
