class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();

        if(n == 1)
            return arr[0];

        int low = 0;
        int high = n - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            bool check1 = true, check2 = true;
            if(mid > 0 && arr[mid] == arr[mid - 1]) {
                if((mid - 1)% 2 == 0) 
                    low = mid + 1;
                if((mid - 1) % 2 == 1)
                    high = mid - 1;
            }

            else if(mid < n - 1 && arr[mid] == arr[mid + 1]) {
                if(mid % 2 == 0)
                    low = mid + 1;
                if(mid % 2 == 1)
                    high = mid - 1;

            }

            else {
                return arr[mid];
            }
        }

        return arr[low];
    }
};