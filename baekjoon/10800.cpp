#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define pii pair<int, int>
using namespace std;

int N, c, s, sum, prevSize, prevCnt, prevColor;

int main() {
  scanf("%d", &N);
  vector<pair<pii, int> > ball;
  vector<int> colorSum(N+1, 0);
  vector<int> colorPrevCnt(N+1, 0);
  vector<int> result(N, 0);
  ball.reserve(N);
  sum = prevSize = prevCnt = prevColor = 0;
  
  for (int i=0; i<N; i++) {
    scanf("%d %d", &c, &s);
    ball.push_back(make_pair(make_pair(s, c), i));
  }
  
  sort(ball.begin(), ball.end());
  
  for (int i=0; i<N; i++) {
    pair<pii, int> p = ball[i];
    result[p.second] = sum - colorSum[p.first.second];
    
    if (prevSize != p.first.first) {
      prevCnt = 0;
    }
    
    if (prevSize != p.first.first || prevColor != p.first.second) {
      colorPrevCnt[p.first.second] = 0;
    }
    
    if (prevSize == p.first.first) {
      result[p.second] -= prevSize*(prevCnt - colorPrevCnt[p.first.second]);
    }
    
    sum += p.first.first;
    colorSum[p.first.second] += p.first.first;
    colorPrevCnt[p.first.second] += 1;
    prevCnt += 1;
    prevSize = p.first.first;
    prevColor = p.first.second;
  }
  
  for (int i=0; i<N; i++) {
    printf("%d\n", result[i]);
  }
}

/*
  색이 다르다면 가벼운 공이 먹을 수 있는 공은 더 무거운 공도 먹을 수 있다는 점에서 아이디어를 얻었다.
  먼저 모든 공을 무게 오름차순으로 정렬한다. 그리고 공을 순서대로 방문할 때마다 무게의 누적합, 해당 색깔의 누적합, 해당 크기가 연속으로 나온 횟수, 색깔 별 해당 크기가 연속으로 나온 횟수 등을 저장한다.
  우선, 주어진 공이 먹을 수 있는 공의 누적합은 기본적으로 (총 누적합 - 해당 색깔 공의 누적합)이다. 그리고 여기에 동일 크기의 공이 연속으로 나온 경우를 고려하여 추가적으로 누적합에서 값을 빼준다.
  
  마지막 과정에서 자꾸 헛다리를 짚어 많이 틀렸다...
*/