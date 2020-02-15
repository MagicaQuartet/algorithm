#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, cost[16][16], cache[16][1<<16];
int solve(int city, int visited) {
  if (visited == (1<<N)-1) {
    return 0;
  }
  if (cache[city][visited] != -1) {
    return cache[city][visited];
  }
  
  int ret = 987654321;
  for (int i=0; i<N; i++) {
    int mask = 1<<i;
    if (cost[city][i] == 0 || visited&mask) continue;
    if (i==0 && visited != (1<<N)-2) continue;
    
    ret = min(ret, cost[city][i]+solve(i, visited|mask));
  }
  cache[city][visited] = ret;
  return ret;
}
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &cost[i][j]);
    }
    for (int j=0; j<(1<<16); j++) {
      cache[i][j] = -1;
    }
  }
  
  printf("%d\n", solve(0, 0));
}


/* 1. 각 도시의 방문 여부를 bit로 나타낸 정수 활용, 이를 이용해 메모이제이션 */
/* 2. 최적해의 경로는 항상 사이클이므로 어느 도시에서 시작하나 답은 똑같다. 따라서 처음에 루프를 돌 필요가 없음. */
/* 3. 0번 도시에서 시작한다고 가정하면, 다른 모든 도시를 돌 때까지 0번 도시에는 다시 돌아와서는 안됨. line 18의 조건문이 해당 경우를 체크 */