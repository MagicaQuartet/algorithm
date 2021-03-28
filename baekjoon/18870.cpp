#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int N, arr[1000010], sorted[1000010];
int main() {
  scanf("%d", &N);
  map<int, int> m;
  for (int i=0; i<N; i++) {
    scanf("%d", arr+i);
    sorted[i] = arr[i];
  }
  sort(sorted, sorted+N);
  int prevNum = -1000000001;
  int idx = 0;
  for (int i=0; i<N; i++) {
    if (prevNum == sorted[i]) {
      continue;
    }
    m[sorted[i]] = idx++;
    prevNum = sorted[i];
  }
  for (int i=0; i<N; i++) {
    printf("%d ", m[arr[i]]);
  }
  printf("\n");
}
