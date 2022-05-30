class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        vector<char> visited(nums.size() + 1, 0);
        for (auto n : nums) {
            visited[n] = 1;
        }
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};