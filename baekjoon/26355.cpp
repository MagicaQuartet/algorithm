#include<cstdio>
#include<cstring>
using namespace std;
int T, num;
int dist[10010];
void init() {
  for (int i=2; i<=100; i++) {
    for (int j=2; i*j <= 10009; j++) {
      dist[i*j] = -1;
    }
  }
  int ldist = 0;
  int rdist = 0;
  for (int i=2; i<=10009; i++) {
    if (dist[i] == 0) {
      ldist = 0;
      continue;
    }
    dist[i] = ++ldist;
  }
  for (int i=10009; i>=2; i--) {
    if (dist[i] == 0) {
      rdist = 0;
      continue;
    }
    if (dist[i] > rdist+1) {
      dist[i] = ++rdist;
    }
  }
}
int main() {
  scanf("%d", &T);
  memset(dist, 0, sizeof(dist));
  init();
  while(T--) {
    scanf("%d", &num);
    printf("Input value: %d\n", num);
    if (dist[num] == 0) {
      printf("Would you believe it; it is a prime!\n");
    }
    else {
      printf("Missed it by that much (%d)!\n", dist[num]);
    }
    printf("\n");
  }
}
