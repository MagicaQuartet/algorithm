#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
int N, L, cnt, covered;
int main() {
  vector<pair<int, int> > data;
  scanf("%d %d", &N, &L);
  
  for (int i=0; i<N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    data.push_back(make_pair(a, b-1));
  }
  
  sort(data.begin(), data.end());
  cnt = 0;
  covered = -1;
  for (int i=0; i<N; i++) {
    int src = max(data[i].first, covered+1);
    int dest = data[i].second;
    
    if (src <= dest) {
      int cnt_ = (dest-src+L)/L;
      covered = src + cnt_*L - 1;
      cnt += cnt_;
    }
  }
  
  printf("%d\n", cnt);
}

/*
  한 웅덩이에서 쓴 널빤지가 다음 웅덩이도 덮는지 잘 고려하고
  웅덩이의 끝 지점을 헷갈리지 않으면 되는 문제
*/