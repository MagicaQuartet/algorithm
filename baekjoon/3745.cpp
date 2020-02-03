#include<cstdio>
#include<algorithm>
using namespace std;
int N, data, idx, len, cache[100000];
int main() {
  while(scanf("%d", &N) != EOF) {
    len = 0;
    for (int i=0; i<N; i++) {
      scanf("%d", &data);
      cache[i] = 987654321;
      idx = lower_bound(cache, cache+i, data) - cache;
      cache[idx] = data;
      if (len < idx + 1) {
        len = idx+1;
      }
    }
    printf("%d\n", len);
  }
}

/* input size 때문에 O(nk) 알고리즘으로도 해결이 불가능한 문제이다. 따라서 이진 탐색 또는 lower_bound를 이용한 O(nlogn) 알고리즘으로 풀어야 했다. lower_bound 활용법을 익히자... */