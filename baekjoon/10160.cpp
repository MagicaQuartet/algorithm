#include<cstdio>
#define Q 1000000009
#define ll long long

int N, K;
ll dp[1000010];

int main() {
  scanf("%d %d", &N, &K);
  dp[0] = 1;  
  
  for (int i=1; i<=N; i++) {
    if (i <= 4) {
      dp[i] = (K*dp[i-1])%Q;
    }
    else if (i <= 6){
      dp[i] = (K*dp[i-1] - 2*dp[i-5])%Q;
    }
    else {
      dp[i] = (K*dp[i-1] - 2*dp[i-5] + dp[i-7])%Q;
    }
    
    if (dp[i] < 0) {
      dp[i] += Q;
    }
  }
  
  printf("%lld\n", dp[N]);
}

/*
  처음에는 두번째 점화식까지만 필요한 줄 알았는데, 길이가 7 이상이면 중복으로 지워지는 경우의 수가 생긴다.
  예를 들어, 길이가 7이면 안전한 길이 6의 암호에 글자 하나를 붙인 뒤, ABCBC??와 ABABC??를 배제한다.
  그런데 이 때 ABABCBC는 이미 길이 5였을 때 걸러졌어야 하는 경우의 수이다. 즉, 이 경우는 안전한 길이 6의 암호에 포함되지 않는다.
  이러한 경우를 고려하여, ABCBC?????와 ABABC?????를 배제한 뒤 중복으로 고려된 ABABCBC???를 처리해주는 점화식이 필요하다.
*/