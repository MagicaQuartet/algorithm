#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
int N, a, b, lis, last, cacheLis[100000], cachePrev[500000], lisstring[100000];
vector<pair<int, int> > data;
void restruct(int a, int cnt) {
  if (cnt < 0) return;
  lisstring[cnt] = a;
  restruct(cachePrev[a-1], cnt-1);
}
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d %d", &a, &b);
    data.push_back(make_pair(a, b));
  }
  sort(data.begin(), data.end());
  
  lis = 1;
  last = -1;
  for (int i=0; i<N; i++) {
    cacheLis[i] = -1;
    for (int j=0; j<=i; j++) {
      if (cacheLis[j] == -1 || data[i].second <= data[cacheLis[j]].second) {
        cacheLis[j] = i;
        if (j>0) {
          cachePrev[data[i].first-1] = data[cacheLis[j-1]].first;
        }
        if (lis < j+1) {
          lis = j+1;
          last = data[i].first;
        }
        break;
      }
    }
  }
  printf("%d\n", N-lis);
  
  restruct(last, lis-1);
  
  int idxA = 0;
  int idxLis = 0;
  while (idxA < N) {
    if (data[idxA].first == lisstring[idxLis]) {
      idxLis++;
    }
    else {
      printf("%d\n", data[idxA].first);
    }
    idxA++;
  }
}

/* 빠른 LIS 찾기 + 최적해 역추적... 으... */
/* O(n^2) 알고리즘에서는 각 단계에서 LIS에 포함될 숫자를 정할 수 있기 때문에 편하게 역추적이 가능하지만 O(nk) 알고리즘에서는 그렇지 않기 때문에 역추적을 어떻게 할지 아이디어가 잘 안 떠올랐다. */
/* 여기서 사용한 방식은, cache[i] (i>1일 때)를 변경하면 항상 cache[i]의 앞 숫자는 cache[i-1]가 된다는 점을 이용하여, cachePrev[p] = q가 p 바로 앞에 나오는 숫자가 q임을 나타낸다고 하면 cache[i]를 수정할 때 cachePrev[cache[i]] = cache[i-1] 이런 식으로 저장하였다. 헷갈려서 디테일하게는 다를 수 있지만 대략 이런 방식이다.  */