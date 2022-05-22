class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return dfs(obstacleGrid, dp, 0, 0);
    }

    int dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j) {
        if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size()) {
            return 0;
        }
        if (obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
            return 1;
        }
        return dp[i][j] = dfs(obstacleGrid, dp, i + 1, j) + dfs(obstacleGrid, dp, i, j + 1);
    }
};
