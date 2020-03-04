#include<cstdio>
#include<queue>
#include<algorithm>
#include<utility>
#include<functional>
using namespace std;
int N, t, ans, gap;

struct cmp {
  bool operator() (pair<int, int>& lhs, pair<int, int>& rhs) {
    if (lhs.first == rhs.first) {
      return lhs.second < rhs.second;
    }
    else {
      return lhs.first > rhs.first;
    }
  }
};

int main() {
  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> problem;
  priority_queue<int, vector<int>, greater<int> > selected;
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    int deadline, cup;
    scanf("%d %d", &deadline, &cup);
    
    problem.push(make_pair(deadline, cup));
  }
  
  t = 0;
  
  while(!problem.empty()) {
    if (problem.top().first == t) {
      if (!selected.empty() && problem.top().second > selected.top()) {
        selected.pop();
        selected.push(problem.top().second);
      }
    }
    else if (problem.top().first > t) {
      selected.push(problem.top().second);
      t++;
    }
    problem.pop();
  }
  
  while(!selected.empty()) {
    ans += selected.top();
    selected.pop();
  }
  
  printf("%d\n", ans);
}

/*
  1. 우선 (deadline, cup)을 deadline 오름차순 -> cup 내림차순으로 정렬한다.
     그리고 선택된 문제를 selected에 저장하되, 항상 cup 오름차순 정렬이 되게 한다.
  2. 현재 시간을 t=0으로 두고 하나씩 순회한다.
    2-1. t가 deadline보다 작은 경우 cup을 selected에 넣고 t++
    2-2. t가 deadline과 같을 경우, cup을 selected에 있는 값 중 최솟값과 비교한다.
         cup이 더 클 경우 selected의 최솟값을 빼고 cup을 추가한다.
         이 경우는 기존에 선택한 문제를 빼고 이 문제를 선택하는 것이므로 t는 추가하지 않는다.
    2-3. 이러한 알고리즘을 따르면 t가 deadline보다 큰 경우는 존재하지 않는다. 아마도..
  3. 모든 문제를 순회한 뒤, selected에 들어있는 모든 값을 합한다.
*/