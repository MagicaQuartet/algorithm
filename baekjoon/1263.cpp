#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<int> T;
vector<int> S;

struct cmp {
  bool operator() (int t, int u) {
    if (S[t] != S[u]) {
      return S[t] < S[u];
    }
    else {
      return T[t] > T[u];
    }
  }
};

int main() {
  int n, t, s;
  scanf("%d", &n);
  
  T = vector<int>(n, 0);
  S = vector<int>(n, 0);
  priority_queue<int, vector<int>, cmp> pq;
  
  int deadline = 0;
  
  for (int i=0; i<n; i++) {
    scanf("%d %d", &t, &s);
    T[i] = t;
    S[i] = s;
    if (deadline < s) {
      deadline = s;
    }
    pq.push(i);
  }
  
  while(!pq.empty()) {
    int task = pq.top();
    deadline = deadline < S[task] ? deadline - T[task] : S[task] - T[task];
    pq.pop();
  }
  
  if (deadline < 0) {
    deadline = -1;
  }
  
  printf("%d\n", deadline);
  
  return 0;
}

/* 기본적으로 S가 작은 일부터 큰 일 순서로 처리를 해야한다. S를 기준으로 오름차순 정렬한 결과가 task1, task2, ..., taskN이라면,
   taskK-1의 데드라인은 S[taskK-1]과 taskK의 데드라인 - T[taskK] 중 작은 값인 것을 고려하며 task1까지 계산한다.  */