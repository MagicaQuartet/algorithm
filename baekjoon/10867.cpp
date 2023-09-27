#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, n;
int main() {
  scanf("%d", &N);
  vector<int> v;
  while(N--) {
    scanf("%d", &n);
    v.push_back(n);
  }
  sort(v.begin(), v.end());
  int prev = v[0];
  printf("%d ", prev);
  for (int i=1; i<v.size(); i++) {
    if (prev == v[i]) {
      continue;
    }
    prev = v[i];
    printf("%d ", prev);
  }
  printf("\n");
}
