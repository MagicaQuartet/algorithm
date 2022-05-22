class Solution {
public:
    int countSubstrings(string s) {
        bool dp[1010][1010];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int len = 0; len < s.size(); len++) {
            for (int i = 0; i + len < s.size(); i++) {
                if (len == 0 || (len == 1 && s[i] == s[i + len]) || (s[i] == s[i + len] && dp[i + 1][i + len - 1])) {
                    ans++;
                    dp[i][i + len] = true;
                }
            }
        }
        return ans;
    }
};
