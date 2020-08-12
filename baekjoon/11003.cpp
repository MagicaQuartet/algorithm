#include<cstdio>
#include<algorithm>
#define ll long long
#define INF 1000000001
using namespace std;

int N, L;
int A[5000010];
int subwindow[10000010];

int main() {
  scanf("%d %d", &N, &L);
  for (int i=1; i<=N; i++) {
    scanf("%d", A+i);
  }

  subwindow[0] = INF;
  for (int i=1; i<L && i<=N; i++) {
    subwindow[i] = min(subwindow[i-1], A[i]);
    printf("%d ", subwindow[i]);
  }

  int step = L;
  while(step + L-1 < N) {
    subwindow[L] = A[step];
    for (int i=1; i<=L-1; i++) {
      subwindow[L+i] = min(subwindow[L+i-1], A[step+i]);
      subwindow[L-i] = min(subwindow[L-i+1], A[step-i]);
    }

    for (int i=1; i<=L; i++) {
      printf("%d ", min(subwindow[i], subwindow[i+L-1]));
    }
    step += L;
  }

  subwindow[L] = A[step];
  for (int i=1; i<=L-1; i++) {
      subwindow[L-i] = min(subwindow[L-i+1], A[step-i]);
    }
  for (int i=1; step+i <= N; i++) {
    subwindow[L+i] = min(subwindow[L+i-1], A[step+i]);
  }

  for (int i=1; i<=L && step+i-1<=N; i++) {
    printf("%d ", min(subwindow[i], subwindow[i+L-1]));
  }
  printf("\n");
}

/*
  슬라이딩 윈도우로 풀라는데 말이야 쉽지
  슬라이딩 윈도우란게 뭔가 정형적으로 방법이 보이는게 아니고
  유연하게 문제에 끼워맞춰야 하는 느낌이라 익숙해지지 않으면 생각을 못할 듯..
*/