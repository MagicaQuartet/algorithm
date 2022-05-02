class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp[10010];
        memset(dp, -1, sizeof(dp));
        return dfs(nums, dp, 0) == 1;
    }
    
    int dfs(const vector<int>& nums, int* dp, int idx) {
        if (dp[idx] != -1) {
            return dp[idx];
        }
        if (idx + nums[idx] >= nums.size()-1) {
            return dp[idx] = 1;
        }
        if (nums[idx] == 0) {
            return dp[idx] = 0;
        }
        for (int i=nums[idx]; i>0; i--) {
            if (dfs(nums, dp, idx+i)) {
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
};

/* DP를 활용하면 각 인덱스에서의 도달 가능 여부를 일일이 찾아도 linear time에 가능하다 */
