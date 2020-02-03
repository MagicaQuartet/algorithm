#include<cstdio>
#include<algorithm>
using namespace std;
int N, data[2001], cacheLis[2001], cacheLds[2001];

int lds(int idx) {
  if (cacheLds[idx] != -1) {
    return cacheLds[idx];
  }
  
  int ret = 1;
  for (int i=idx+1; i<=N; i++) {
    if (idx == 0 || data[idx] > data[i]) {
      ret = max(ret, lds(i)+1);
    }
  }
  cacheLds[idx] = ret;
  return ret;
}

int lis(int idx) {
  if (cacheLis[idx] != -1) {
    return cacheLis[idx];
  }
  
  int ret = 1;
  for (int i=idx+1; i<=N; i++) {
    if (idx == 0 || data[idx] < data[i]) {
      ret = max(ret, lis(i)+1);
    }
  }
  cacheLis[idx] = ret;
  return ret;
}
int main() {
  scanf("%d\n", &N);
  cacheLis[0] = cacheLds[0] = -1;
  for (int i=1; i<=N; i++) {
    scanf("%d", data+i);
    cacheLis[i] = cacheLds[i] = -1;
  }
  lds(0);
  lis(0);
  
  int ans = 0;
  for (int i=1; i<=N; i++) {
    ans = max(ans, cacheLds[i]+cacheLis[i]-1);
  }
  printf("%d\n", ans);
}

/* 각 지점에서 시작하여 만들 수 있는 LIS와 LDS의 길이를 빼고 1을 더한다. */