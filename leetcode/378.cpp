class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> arr = flatten(matrix, 0, matrix.size() - 1);
        return arr[k - 1];
    }

    vector<int> flatten(vector<vector<int>>& matrix, int i, int j) {
        if (i >= j) {
            return matrix[i];
        }
        int mid = (i + j) / 2;
        vector<int> left = flatten(matrix, i, mid);
        vector<int> right = flatten(matrix, mid + 1, j);
        return merge(left, right);
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> ret;
        ret.reserve(a.size() * 2);
        int aidx = 0, bidx = 0;
        while (aidx < a.size() && bidx < b.size()) {
            if (a[aidx] < b[bidx]) {
                ret.push_back(a[aidx++]);
            }
            else {
                ret.push_back(b[bidx++]);
            }
        }
        while (aidx < a.size()) {
            ret.push_back(a[aidx++]);
        }
        while (bidx < b.size()) {
            ret.push_back(b[bidx++]);
        }
        return ret;
    }
};
