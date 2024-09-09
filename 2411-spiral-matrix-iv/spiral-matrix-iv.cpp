/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    // sets direction vector
    void helper(int i, int j, int& di, int& dj, vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (i + di >= m || i + di < 0 || j + dj >= n || j + dj < 0 ||
            matrix[i + di][j + dj] != -1) {
            // rotate direction vector by 90 degrees
            if (dj == 1) {
                di = 1; dj = 0;
            } else if (di == 1) {
                di = 0; dj = -1;
            } else if (dj == -1) {
                di = -1; dj = 0;
            } else {
                di = 0; dj = 1;
            }
        }
    }

public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        ListNode* ptr = head;
        int di = 0, dj = 1; // direction vector, move right
        int i = 0, j = 0;
        while (ptr) {
            result[i][j] = ptr->val;
            helper(i, j, di, dj, result); // set direction vector
            i += di;
            j += dj;
            ptr = ptr->next;
        } 
        return result;
    }
};