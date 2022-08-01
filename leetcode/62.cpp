class Solution {
public:
    int search(int x, int y, int dstx, int dsty) {
        if (x > dstx || y > dsty) {
            return 0;
        }
        if (x == dstx && y == dsty) {
            return 1;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        return dp[x][y] = search(x+1, y, dstx, dsty) + search(x, y+1, dstx, dsty);
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return search(0, 0, m-1, n-1);
    }
    
private:
    int dp[101][101];
};
