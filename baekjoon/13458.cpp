#include<cstdio>
int N, B, C, A[1000000];
long long cnt;
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d %d", &B, &C);
  cnt = N;
  for (int i=0; i<N; i++) {
    if (A[i]-B > 0) {
      cnt += (A[i]-B)/C + ((A[i]-B)%C ? 1 : 0);
    }
  }
  printf("%lld\n", cnt);
}