#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
using namespace std;
int N, K;
long long sum;
vector<pair<int, int> > gems;
multiset<int> bags;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  else {
    return a.first > b.first;
  }
}
int main() {
  scanf("%d %d", &N, &K);
  
  for (int i=0; i<N; i++) {
    int M, V;
    scanf("%d %d", &M, &V);
    gems.push_back(make_pair(V, M));
  }
  
  for (int i=0; i<K; i++) {
    int C;
    scanf("%d", &C);
    bags.insert(C);
  }
  
  sort(gems.begin(), gems.end(), cmp);
  
  int idx = 0;
  sum = 0;
  while (idx < N && !bags.empty()) {
    multiset<int>::iterator it;
    
    it = bags.lower_bound(gems[idx].second);
    if (it != bags.end()) {
      sum += gems[idx].first;
      bags.erase(it);
    }
    idx++;
  }
  printf("%lld\n", sum);
}

/*
  1. 보석을 (1) 가격 내림차순 (2) 무게 오름차순으로 정렬한다
  2. 가방을 capacity 오름차순으로 정렬한다
  3. 정렬된 보석 배열에서 각 보석을 담을 수 있는 가방 중 capacity가 가장 낮은 것을 찾는다
*/