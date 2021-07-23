#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, M, B;
int blocks[260];

int main() {
  scanf("%d %d %d", &N, &M, &B);
  memset(blocks, 0, size(blocks));
  int need = 0;
  int maxHeight = 0;
  int minCost = 987654321;
  int accCost = 0;
  int ans = -1;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      int h;
      scanf("%d", &h);
      if (h > 256) {
        B += (h-256);
        h = 256;
      }
      maxHeight = max(maxHeight, h);
      blocks[h]++;
    }
  }

  for (int i=0; i<maxHeight; i++) {
    need += (maxHeight-i)*blocks[i];
  }

  for (int i=maxHeight; i>=0; i--) {
    if (i == 0) {
      if (accCost < minCost) {
        minCost = accCost;
        ans = 0;
      }
      break;
    }

    if (need <= B) {
      int cost = need + accCost;
      if (cost < minCost) {
        minCost = cost;
        ans = i;
      }
    }

    accCost += blocks[i]*2;
    B += blocks[i];
    need -= (N*M) - blocks[i];
    blocks[i-1] += blocks[i];
    blocks[i] = 0;
  }

  printf("%d %d\n", minCost, ans);
}
