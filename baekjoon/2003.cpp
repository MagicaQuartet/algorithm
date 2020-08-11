#include<cstdio>

int N, M, sum, ans, i, j;
int nums[10010];

int main() {
  scanf("%d %d", &N, &M);
  ans = i = j = 0;

  for (int i=0; i<N; i++) {
    scanf("%d", nums+i);
  }

  sum = nums[0];
  while(j < N) {
    if (sum == M) {
      ans++;
      sum -= nums[i];
      i++;
      j++;
      sum += nums[j];
    }
    else if (i == j) {
      j++;
      sum += nums[j];
    }
    else if (sum < M) {
      j++;
      sum += nums[j];
    }
    else if (sum > M) {
      sum -= nums[i];
      i++;
    }
  }
  printf("%d\n", ans);
}

/*
  2 pointers
*/