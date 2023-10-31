#include<cstdio>
int N, S, P;
int main() {
  scanf("%d%d%d", &N, &S, &P);
  int rank = -1;
  int num = -1;
  for (int i=1; i<=N && i<=P; i++) {
    scanf("%d", &num);
    if (S >= num && rank == -1) {
      rank = i;
    }
    if (rank != -1 && S > num) {
      break;
    }
  }
  if (num == -1) {
    printf("1\n");
  }
  else if (N < P) {
    printf("%d\n", rank > -1 ? rank : N+1);
  }
  else if (S > num) {
    printf("%d\n", rank);
  }
  else {
    printf("-1\n");
  }
}
