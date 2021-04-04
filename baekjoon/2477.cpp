#include<cstdio>
#include<algorithm>
using namespace std;
int K, len[6], direction[6];
int main() {
  scanf("%d", &K);
  scanf("%d %d %d %d", direction, len, direction+1, len+1);
  int maxx = (direction[0] <= 2) ? len[0] : len[1];
  int maxy = (direction[0] <= 2) ? len[1] : len[0];
  int cutx, cuty;
  for (int i=2; i<6; i++) {
    scanf("%d %d", direction+i, len+i);
    if (direction[i] <= 2) {
      maxx = max(maxx, len[i]);
    }
    else {
      maxy = max(maxy, len[i]);
    }
  }
  for (int i=3; i<12; i++) {
    int a = (i-3)%6;
    int b = (i-2)%6;
    int c = (i-1)%6;
    int d = i%6;
    if (direction[a] == direction[c] && direction[b] == direction[d]) {
      cutx = len[b];
      cuty = len[c];
      break;
    }
  }
  printf("%d\n", (maxx*maxy-cutx*cuty)*K);
}
