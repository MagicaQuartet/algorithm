#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int T, N, a, b, limit, ans;
vector<pair <int, int> > data;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    data.clear();
    data.reserve(N);
    limit = N+1;
    ans = 0;
    for (int i=0; i<N; i++) {
      scanf("%d %d", &a, &b);
      data.push_back(make_pair(a, b));
    }
    sort(data.begin(), data.end());
    
    for (auto p : data) {
      if (p.second < limit) {
        ans++;
        limit = p.second;
      }
      
      if (limit == 1) break;
    }
    
    printf("%d\n", ans);
  }
}

/*
  어느 한 쪽의 등수를 기준으로 정렬한 후 내림차순으로 순회하며
  반대쪽의 등수가 순회하는 시점까지의 최고등수보다 높은 경우를 카운트한다.
  여기서는 간단하게 일단 데이터를 받고 정렬시키는 방법을 썼지만 정적 배열을 사용하여 입력받는 동시에 정렬을 하면 더 빠르게 풀 수 있다.
*/