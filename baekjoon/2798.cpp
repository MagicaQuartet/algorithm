#include<cstdio>

int N, M;
int cards[110];

int main() {
  scanf("%d %d", &N, &M);
  int maxVal = 0;

  for (int i=0; i<N; i++) {
    int card;
    scanf("%d", &card);
    cards[i] = card;
  }

  for (int i=0; i<N-2; i++) {
    for (int j=i+1; j<N-1; j++) {
      for (int k=j+1; k<N; k++) {
        int sum = cards[i]+cards[j]+cards[k];
        if (sum == M) {
          printf("%d\n", M);
          return 0;
        }

        if (sum < M && maxVal < sum) {
          maxVal = sum;
        }
      }
    }
  }

  printf("%d\n", maxVal);
}