#include<cstdio>
#include<cstring>
int n, k, c, coin[100], dp[10001];
int main() {
  memset(dp, 0, 40004);
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", &c);
    coin[i] = c;
  }
  
  for (int i=0; i<n; i++) {
    for (int j=1; j<=k; j++) {
      if (coin[i] == j) {
        dp[j] += 1;
      }
      else if (coin[i] < j) {
        dp[j] += dp[j-coin[i]];
      }
    }
  }
  
  printf("%d\n", dp[k]);
}

/* 진짜 좋은 문제! */
/* 메모리 사용을 줄이기 위해 어떻게 1차원 dp로 문제를 해결할지 고민해야 하는 문제 */
/* 재귀는 시간 제한에 걸려서 불가능하니 중복을 피하여 경우의 수를 구할 수 있는 방법을 생각해야함 */
/* Hint: 순서 고정 */