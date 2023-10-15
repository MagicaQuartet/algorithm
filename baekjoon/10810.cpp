#include<cstdio>
#include<cstring>
using namespace std;
int N, M, i, j, k;
int bucket[110];
int main() {
  scanf("%d%d", &N, &M);
  memset(bucket, 0, sizeof(bucket));
  while(M--) {
    scanf("%d%d%d", &i, &j, &k);
    for (int idx=i; idx<=j; idx++) {
      bucket[idx] = k;
    }
  }
  for (int i=1; i<=N; i++) {
    printf("%d ", bucket[i]);
  }
}
