#include<cstdio>

using namespace std;

int main() {
  int N, temp, answer;
  
  scanf("%d", &N);
  
  int *foo = new int[N];
  int *dp = new int[N];
  
  for (int i=0; i<N; i++) {
    scanf("%d", &temp);
    foo[i] = dp[i] = temp;
  }
  
  for (int i=N-2; i>=0; i--) {
    int max = 0;
    for (int j=i+1; j<N; j++) {
      if (foo[i]<foo[j]) {
        if (max < dp[j])
          max = dp[j];
      }          
    }
    dp[i] += max;
  }
  
  answer = 0;
  for (int i=0; i<N; i++) {
    if (answer < dp[i])
      answer = dp[i];
  }
  
  printf("%d\n", answer);
  return 0;
}

/* O(N^2) Dynamic programming */