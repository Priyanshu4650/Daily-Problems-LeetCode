class Solution {
    bool comparator(int a, int b) { 
        if(priority[a] > priority[b]) {
            return true;
        }
        if(priority[a] == 0 && priority[b] == 0) {
            return a > b;
        }
        return false;
    }
public:
    unordered_map<int, int> priority;
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        for(int i=0;i<n;i++) {
            priority[arr2[i]] = n - i;
        }

        for(int i=0;i<arr1.size();i++) {
            if(!priority[arr1[i]]) {
                priority[arr1[i]] = 0;
            }
        }

        for(auto it : priority) {
            cout << it.first << " " << it.second << endl;
        }

        for(int i=0;i<arr1.size();i++) {
            for(int j=i + 1;j<arr1.size();j++) {
                if(priority[arr1[j]] > priority[arr1[i]]) {
                    swap(arr1[i], arr1[j]);
                }
                if(priority[arr1[i]] == priority[arr1[j]] && arr1[i] > arr1[j]) {
                    swap(arr1[i], arr1[j]);
                }
            }
        }

        return arr1;
    }
};