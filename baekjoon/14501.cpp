#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

struct Consult {
  int date;
  int duration;
  int pay;
};

struct cmp {
  bool operator() (Consult lhs, Consult rhs) {
    if ((lhs.date+lhs.duration) > (rhs.date+rhs.duration))
      return true;
    else if ((lhs.date+lhs.duration) < (rhs.date+rhs.duration))
      return false;
    else
      return lhs.date > rhs.date;
  }
};

int main() {
  int N, t, p, step;
  vector<int> dp;
  priority_queue<Consult, vector<Consult>, cmp> pq;
  
  cin >> N;
  
  for (int i=0; i<N; i++) {
    dp.push_back(0);
    cin >> t >> p;
    
    if (i+t > N)
      continue;
    
    Consult foo;
    foo.date = i+1;
    foo.duration = t;
    foo.pay = p;
    
    pq.push(foo);
  }
  
  dp.push_back(0);
  step = 0;
  
  while (!pq.empty()) {
    Consult consult = pq.top();
    
    while (step < consult.date+consult.duration) {
      step += 1;
      dp[step] = dp[step-1];
    }
    
    if (dp[step] < dp[consult.date] + consult.pay)
      dp[step] = dp[consult.date] + consult.pay;
    
    pq.pop();
  }
  
  while (step < N+1) {
    step += 1;
    dp[step] = dp[step-1];
  }
  
  cout << dp[N+1] << endl;
  
  return 0;
}

/* Dynamic programming을 이용해 N번째 날까지 얻을 수 있는 최대 이익을 계산한다 */