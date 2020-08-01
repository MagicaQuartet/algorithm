#include<cstdio>
#include<cstring>

int N, M;
int score[110];
int target[110];

int main() {
  scanf("%d %d", &N, &M);
  memset(score, 0, sizeof(score));

  for (int i=0; i<M; i++) {
    int t;
    scanf("%d", &t);
    target[i] = t-1;
  }

  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      int guess;
      scanf("%d", &guess);
      guess--;

      if (guess == target[i]) {
        score[j]++;
      }
      else {
        score[target[i]]++;
      }
    }
  }

  for (int i=0; i<N; i++) {
    printf("%d\n", score[i]);
  }
}