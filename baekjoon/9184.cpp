#include<cstdio>
#include<cstring>
int a, b, c;
int dp[21][21][21];
int recursive(int x, int y, int z) {
  if (x <= 0 || y <= 0 || z <= 0) {
    return 1;
  }
  if (x > 20 || y > 20 || z > 20) {
    return recursive(20, 20, 20);
  }
  if (dp[x][y][z] != -1) {
    return dp[x][y][z];
  }
  if (x < y && y < z) {
    return dp[x][y][z] = recursive(x, y, z-1) + recursive(x, y-1, z-1) - recursive(x, y-1, z);
  }
  else {
    return dp[x][y][z] = recursive(x-1, y, z) + recursive(x-1, y-1, z) + recursive(x-1, y, z-1) - recursive(x-1, y-1, z-1);
  }
}
int main() {
  while (1) {
    scanf("%d %d %d", &a, &b, &c);
    memset(dp, -1, sizeof(dp));
    if (a==-1 && b==-1 && c==-1) break;
    printf("w(%d, %d, %d) = %d\n", a, b, c, recursive(a, b, c));
  }
}