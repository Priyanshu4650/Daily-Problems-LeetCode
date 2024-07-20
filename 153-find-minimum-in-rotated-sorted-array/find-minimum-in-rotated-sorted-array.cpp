#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return arr[0]; // Single element array case
        }
        
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the pivot point
            if (mid > 0 && arr[mid] < arr[mid - 1]) {
                return arr[mid];
            }
            
            // Determine which half to continue searching
            if (arr[mid] >= arr[low] && arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // At the end of the loop, low should point to the minimum element
        return arr[low];
    }
};
