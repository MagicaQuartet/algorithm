#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int N, C, M, cnt;
int main() {
  scanf("%d %d %d", &N, &C, &M);
  vector<pair<pair<int, int>, int> > box(M, make_pair(make_pair(0, 0), 0));
  vector<int> capacity(N, C);
  
  for (int i=0; i<M; i++) {
    scanf("%d %d %d", &box[i].first.second, &box[i].first.first, &box[i].second);
  }
  
  sort(box.begin(), box.end());
  
  cnt = 0;
  for (int i=0; i<M; i++) {
    int src = box[i].first.second;
    int dest = box[i].first.first;
    int b = box[i].second;
    
    int minCapacity = 10001;
    for (int j=src; j<dest; j++) {
      minCapacity = min(minCapacity, capacity[j-1]);
    }
    
    int send = min(minCapacity, b);
    cnt += send;
    for (int j=src; j<dest; j++) {
      capacity[j-1] -= send;
    }
  }
  
  printf("%d\n", cnt);
}

/*
  조금 더 단순하게 생각할 필요가 있었다. 예쁘고 깔끔하게만 풀려고 하는 습관을 버리자...
  우선 dest 오름차순으로 정렬하고, 각 마을에서의 capacity를 저장하는 배열을 만든다.
  그리고 하나의 쿼리를 체크할 때 마다 해당 구간의 capacity를 조정하며 모든 쿼리를 순회한다.
  
  capacity를 조정하는게 O(NM)으로 번거로워 보여서 (==예쁘고 깔끔하지 않아서) 오히려 힘들게 돌아가려 했던 것 같다. 풀 수 있는 방법이 있으면 그냥 일단 시도할 것.
*/