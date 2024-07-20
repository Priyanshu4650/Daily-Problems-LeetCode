class SegmentTree {
public:
    void build(vector<int>& tree, int node, int st, int end, vector<int>& arr) {
        if (st == end) {
            tree[node] = arr[st];
            return;
        }

        int mid = (st + end) / 2;
        build(tree, 2 * node, st, mid, arr);
        build(tree, 2 * node + 1, mid + 1, end, arr);

        // Sum operation for building segment tree
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int st, int end, int l, int r, vector<int>& tree, int lower, int upper) {
        if (st > r || end < l) {
            return 0;
        }

        if (st >= l && end <= r) {
            // Check if the node value falls within [lower, upper]
            if (tree[node] >= lower && tree[node] <= upper) {
                return 1;
            } else {
                return 0;
            }
        }


        int count = 0;
        int mid = (st + end) / 2;
        if(tree[mid] >= lower && tree[mid] <= upper) 
            count += 1;

        count += query(2 * node, st, mid, l, r, tree, lower, upper);
        count += query(2 * node + 1, mid + 1, end, l, r, tree, lower, upper);

        cout << tree[node] << " " << count << endl;
        return count;
    }

    int printTree(vector<int>& tree) {
        int count = 0;
        for (int i = 1; i < tree.size(); ++i) {
            if (tree[i] != INT_MAX)
            {
                cout << tree[i] << " ";
                count += 1;
            }
        }
        cout << endl;

        return count;
    }
};

class Solution {
public:
    void mergeArray(vector<long long>& sum, int left, int mid, int right){
    vector<long long> tmp(right-left+1);
    int i = left, j = mid+1, k = 0;
    while(i <= mid && j <= right){
        tmp[k++] = sum[i] <= sum[j]? sum[i++] : sum[j++];
    }
    while(i <= mid){
        tmp[k++] = sum[i++];
    }
    while(j <= right){
        tmp[k++] = sum[j++];
    }
    i = left, k = 0;
    while(i <= right){
        sum[i++] = tmp[k++];
    }
}
int mergeCount(vector<long long>& sum, int left, int right, int lower, int upper){
    if(left == right){
        return sum[left] >= lower && sum[right] <= upper? 1 : 0;
    }
    int count = 0;
    int mid = left + ((right-left)>>1);
    int leftCount = mergeCount(sum, left, mid, lower, upper);
    int rightCount = mergeCount(sum, mid+1, right, lower, upper);
    int i = left, k = mid+1, j = mid+1;
    while(i <= mid){
        long long lowerBound = sum[i]+lower, upperBound = sum[i]+upper;
        while(j <= right && sum[j] <= upperBound){
            ++j;
        }
        while(k <= right && sum[k] < lowerBound){
            ++k;
        }
        count += (j-k);
        ++i;
    }
    mergeArray(sum, left, mid, right);
    return leftCount+rightCount+count;
}
//Time O(NlogN), Space O(N)
int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<long long> sum(nums.size(), 0);
    sum[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        sum[i] = sum[i-1]+nums[i];
    }
    return mergeCount(sum, 0, sum.size()-1, lower, upper);
}
};
