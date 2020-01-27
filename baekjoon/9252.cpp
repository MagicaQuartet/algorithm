#include<cstdio>
#include<algorithm>
using namespace std;
char A[1001], B[1001], ans[1001];
int dp[1001][1001], i, j;
int main() {
  scanf("%s %s", A, B);
  for (i=0; i<1001; i++) {
    dp[0][i] = dp[i][0] = 0;
  }
  for (i=1; A[i-1]>0; i++) {
    for (j=1; B[j-1]>0; j++) {
      if (A[i-1] == B[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  i--;
  j--;
  printf("%d\n", dp[i][j]);
  ans[dp[i][j]] = 0;
  while(dp[i][j]!=0) {
    if (dp[i][j] == dp[i-1][j]) {
      i--;
    }
    else if (dp[i][j] == dp[i][j-1]) {
      j--;
    }
    else if (dp[i][j] - 1 == dp[i-1][j-1]) {
      ans[dp[i-1][j-1]] = A[i-1];
      i--;
      j--;
    }
  }
  printf("%s\n", ans);
}

/* dp를 int배열이 아니라 char배열로 선언해버려서 1시간 동안 에러 못잡고 쇼를 하고 있었다...주의하자 */

/* LCS1 문제와는 달리 LCS 문자열도 구해야하기 때문에 1차원 배열만으로는 충분하지 않다...고 생각한다. 그래서 일단 2차원 dp를 작성한 다음 역으로 문자열을 추적하였다. */
/* 문자열을 추적할 때에도, 길이가 같은 CS들이 여러 개 존재할 수 있으나 아무거나 집어가면 올바르지 않은 LCS가 완성되지 않을 수도 있으므로 주의해야한다. 여기서는 dp 테이블의 i, j 지점에서 위쪽 혹은 왼쪽의 값과 같으면 그쪽으로 이동하고, 그렇지 않고 왼쪽 위의 값과 1이 차이가 나면 A[i-1] 문자를 LCS에 추가하고 i-1, j-1 지점으로 이동하면서 탐색하였다. */