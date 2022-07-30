class Solution {
public:
    int searchLeft(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        int retLeft = -1;
        int retRight = -1;
        if (nums[mid] >= target) {
            retLeft = searchLeft(nums, target, left, mid - 1);
        }
        else {
            retRight = searchLeft(nums, target, mid + 1, right);
        }
        if (retLeft == -1 && retRight == -1) {
            return nums[mid] == target ? mid : -1;
        }
        else if (retRight == -1) {
            return retLeft;
        }
        else if (retLeft == -1) {
            return nums[mid] == target ? mid : retRight;
        }
        else {
            return retLeft;
        }
    }

    int searchRight(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        int retLeft = -1;
        int retRight = -1;
        if (nums[mid] > target) {
            retLeft = searchRight(nums, target, left, mid - 1);
        }
        else {
            retRight = searchRight(nums, target, mid + 1, right);
        }
        if (retLeft == -1 && retRight == -1) {
            return nums[mid] == target ? mid : -1;
        }
        else if (retLeft == -1) {
            return retRight;
        }
        else if (retRight == -1) {
            return nums[mid] == target ? mid : retLeft;
        }
        else {
            return retRight;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        ret.push_back(searchLeft(nums, target, 0, nums.size() - 1));
        ret.push_back(searchRight(nums, target, 0, nums.size() - 1));
        return ret;
    }
};
