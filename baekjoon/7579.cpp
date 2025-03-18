#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#define pii pair<int, int> 
using namespace std;
int N, M, m[100], c[100], costmax[10010];
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", m + i);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", c + i);
  }
  memset(costmax, -1, sizeof(costmax));
  costmax[0] = 0;
  int ans = -1;
  for (int i = 0; i < N; i++) {
    for (int cost = 10000; cost >= 0; cost--) {
      if (costmax[cost] != -1) {
        if (costmax[cost] + m[i] >= M) {
          ans = (ans == -1 || ans > cost + c[i]) ? cost + c[i] : ans;
        }
        else if (costmax[cost + c[i]] == -1 || costmax[cost + c[i]] < costmax[cost] + m[i]) {
          costmax[cost + c[i]] = costmax[cost] + m[i];
        }
      }
    }
  }
  printf("%d\n", ans);
}