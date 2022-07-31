class NumArray {
public:
    NumArray(vector<int>& nums) {
        len = nums.size();
        segtree = vector<int>(4*len, 0);
        _build(nums, 1, 0, len-1);
    }
    
    void update(int index, int val) {
        _update(1, 0, len-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return _sumRange(1, 0, len-1, left, right);   
    }
    
private:
    vector<int> segtree;
    int len;
    
    int _build(vector<int>& nums, int node, int left, int right) {
        if (left == right) {
            return segtree[node] = nums[left];
        }
        int mid = (left+right)/2;
        return segtree[node] = _build(nums, 2*node, left, mid) + _build(nums, 2*node+1, mid+1, right);
    }
    
    void _update(int node, int left, int right, int target, int val) {
        if (target < left || right < target) {
            return;
        }
        if (left == right) {
            segtree[node] = val;
            return;
        }
        int mid = (left+right)/2;
        _update(2*node, left, mid, target, val);
        _update(2*node+1, mid+1, right, target, val);
        segtree[node] = segtree[2*node]+segtree[2*node+1];
    }
    
    int _sumRange(int node, int left, int right, int targetLeft, int targetRight) {
        if (targetRight < left || right < targetLeft) {
            return 0;
        }
        if (targetLeft <= left && right <= targetRight) {
            return segtree[node];
        }
        int mid = (left+right)/2;
        return _sumRange(2*node, left, mid, targetLeft, targetRight) + _sumRange(2*node+1, mid+1, right, targetLeft, targetRight);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
