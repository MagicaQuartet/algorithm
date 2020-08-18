#include<cstdio>
#define ll long long

int N;
int nums[110];
ll dp[22][110];

ll solve(int idx, int sum) {
  if (sum < 0 || sum > 20) {
    return 0;
  }

  if (idx == N-1) {
    return (sum == nums[idx]) ? 1 : 0;
  }

  if (dp[sum][idx] != -1) {
    return dp[sum][idx];
  }

  return dp[sum][idx] = solve(idx+1, sum+nums[idx]) + solve(idx+1, sum-nums[idx]);
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf("%d", nums+i);
    for (int j=0; j<=20; j++) {
      dp[j][i] = -1;
    }
  }

  printf("%lld\n", solve(1, nums[0]));
}

/*
  일일이 다 해보기에 2^100은 너무 큰 수이기 때문에 DP 활용 필요
*/