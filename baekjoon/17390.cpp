#include<cstdio>
#include<algorithm>
using namespace std;
int N, Q, L, R, data[300001];
int main() {
  scanf("%d %d", &N, &Q);
  data[0] = 0;
  for (int i=1; i<=N; i++) {
    scanf("%d", data+i);
  }
  sort(data+1, data+N+1);
  for (int i=1; i<=N; i++) {
    data[i] += data[i-1];
  }
  
  for (int i=0; i<Q; i++) {
    scanf("%d %d", &L, &R);
    printf("%d\n", data[R]-data[L-1]);
  }
}

/*
  부분합
*/