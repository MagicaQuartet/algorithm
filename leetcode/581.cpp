class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int incNum = nums[0];
        int lhsIdx = -1;
        int rhsIdx = -1;
        int minNum = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (incNum <= nums[i]) {
                incNum = nums[i];
            }
            else if (lhsIdx == -1) {
                lhsIdx = i;
                rhsIdx = i;
                minNum = nums[i];
            }
            else {
                rhsIdx = i;
                minNum = min(minNum, nums[i]);
            }
        }
        if (lhsIdx == -1) {
            return 0;
        }
        for (int i = lhsIdx - 1; i >= 0; i--) {
            if (nums[i] > minNum) {
                lhsIdx = i;
            }
        }
        return rhsIdx - lhsIdx + 1;
    }
};
