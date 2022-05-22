class Solution {
public:
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, solve(matrix, dp, i, j));
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= matrix.size() || ny >= matrix[0].size() || nx < 0 || ny < 0) {
                continue;
            }
            if (matrix[nx][ny] <= matrix[i][j]) {
                continue;
            }
            ans = max(ans, solve(matrix, dp, nx, ny));
        }
        return dp[i][j] = ans + 1;
    }
};
