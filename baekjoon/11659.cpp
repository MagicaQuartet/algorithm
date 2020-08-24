#include<cstdio>
#include<utility>
using namespace std;
int N, M, i, j;
int accSum[100010];

int main() {
  accSum[0] = 0;
  scanf("%d %d", &N, &M);

  for (int i=1; i<=N; i++) {
    scanf("%d", accSum+i);
    accSum[i] += accSum[i-1];
  }

  while(M--) {
    scanf("%d %d", &i, &j);
    if (i>j) {
      swap(i, j);
    }
    printf("%d\n", accSum[j]-accSum[i-1]);
  }
}