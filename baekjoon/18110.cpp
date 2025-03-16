#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int scores[300010];
int main() {
  scanf("%d", &N);
  if (N == 0) {
    printf("0\n");
    return 0;
  }
  for (int i=1; i<=N; i++) {
    scanf("%d", &scores[i]);
  }
  sort(scores+1, scores+N+1);
  int sum = 0;
  int cut = (N*15+50)/100;
  for (int i=cut+1; i<=N-cut; i++) {
    sum += scores[i];
  }
  printf("%d\n", ((sum+(N-2*cut)/2)/(N-2*cut)));
}
