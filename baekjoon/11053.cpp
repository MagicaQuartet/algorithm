#include<cstdio>
#include<vector>

using namespace std;

int main() {
  int N, temp, answer;
  scanf("%d", &N);
  
  int *foo = new int[N];
  int *dp = new int[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &temp);
    foo[i] = temp;
    dp[i] = 1;
  }
  
  for (int i=N-2; i>=0; i--) {
    for (int j=i+1; j<N; j++) {
      if (foo[i] < foo[j] && dp[i] < dp[j]+1)
        dp[i] = dp[j] + 1;
    }
  }
  
  answer = 0;
  for (int i=0; i<N; i++) {
    if (answer < dp[i])
      answer = dp[i];
  }
  
  printf("%d\n", answer);
  
  return 0;
}

/* 괜히 이상한 거 떠올릴 필요 없이 Dynamic programming O(N^2)로 해도 된다. */