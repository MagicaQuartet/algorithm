class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        int cur = 0;
        int prv = -1;
        for (auto n : nums) {
            if (ans == 0 || n <= prv) {
                cur = 1;
            }
            else {
                cur++;
            }
            prv = n;
            if (ans < cur) {
                ans = cur;
            }
        }
        return ans;
    }
};