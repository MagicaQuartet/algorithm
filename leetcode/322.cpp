class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10010];
        memset(dp, -1, sizeof(dp));
        for (auto c : coins) {
            if (amount < c) {
                continue;
            }
            dp[c] = 1;
        }
        dp[0] = 0;
        for (int i = 2; i <= amount; i++) {
            for (auto c : coins) {
                if (i - c < 0 || dp[i - c] == -1) {
                    continue;
                }
                dp[i] = dp[i] != -1 ? min(dp[i], dp[i - c] + 1) : dp[i - c] + 1;
            }
        }
        return dp[amount];
    }
};
