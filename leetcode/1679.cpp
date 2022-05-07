class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lhs = 0;
        int rhs = nums.size() - 1;
        int answer = 0;
        while (lhs < rhs) {
            int sum = nums[lhs] + nums[rhs];
            if (sum == k) {
                answer++;
                lhs++;
                rhs--;
            }
            else if (sum < k) {
                lhs++;
            }
            else {
                rhs--;
            }
        }
        return answer;
    }
};