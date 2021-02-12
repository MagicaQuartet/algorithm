#include<cstdio>
#include<cstring>
int N, M, first, second;
int point[10010];
int main() {
  while (1) {
    scanf("%d %d", &N, &M);
    if (N == 0) break;

    first = second = -1;
    memset(point, 0, sizeof(point));
    while (N--) {
      int ranker;
      for (int i=0; i<M; i++) {
        scanf("%d", &ranker);
        point[ranker]++;
      }
    }

    for (int i=1; i<=10000; i++) {
      if (point[i] > first) {
        second = first;
        first = point[i];
      }
      else if (point[i] > second) {
        second = point[i];
      }
    }

    for (int i=1; i<=10000; i++) {
      if (point[i] == second) printf("%d ", i);
    }
    printf("\n");
  }
}