#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N, fibo[25], mindp[20000], maxdp[20000];
void fiboCalc() {
  fibo[0] = 1;
  fibo[1] = 2;
  
  for (int i=2; i<25; i++) {
    fibo[i] = fibo[i-1] + fibo[i-2];
  }
}
int main() {
  scanf("%d", &N);
  fiboCalc();
  
  mindp[0] = mindp[1] = maxdp[0] = maxdp[1] = 0;
  mindp[2] = maxdp[2] = 1;
  mindp[3] = maxdp[3] = 2;
  
  for (int i=4; i<=N; i++) {
    mindp[i] = 987654321;
    maxdp[i] = 0;
    for (int f=1; fibo[f]<=N; f++) {
      if (i-fibo[f] >= 2) {
        mindp[i] = min(mindp[i], mindp[i-fibo[f]] + fibo[f-1]);
        maxdp[i] = max(maxdp[i], maxdp[i-fibo[f]] + fibo[f-1]);
      }
    }
  }
  
  printf("%d %d", mindp[N], maxdp[N]);
}

/*
  N이 주어졌을 때 가능한 최솟값과 최댓값을 DP로 구했다.
  피보나치수는 1, 2, ..로 시작할 때 25번째 쯤 되면 대충 7만쯤 되므로 그정도로 잡아두면 충분할 것.
  
  dp를 구할 때 초기값이나 세부 조건 등을 신경써줘야 해서 조금 헷갈렸지만 아무튼 이렇게 해결 가능.
  
  (수정) 음 다른 풀이를 보니 간단한 수학적 풀이가 있는 모양인데 왜 그렇게 되는지는 모르겠다...
  일단 답은 N/2+1, N/3*2+N%3 라고 한다.
*/