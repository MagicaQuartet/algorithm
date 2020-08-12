#include<cstdio>
#include<queue>
#define INF 987654321
using namespace std;

struct cmp {
  bool operator() (int lhs, int rhs) {
    return lhs > rhs;
  }
};

int N, mid = INF;
priority_queue<int> lesspq;
priority_queue<int, vector<int>, cmp> morepq;

int main() {
  scanf("%d", &N);

  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);

    if (lesspq.empty() && morepq.empty()) {
      if (mid == INF) {
        mid = num;
      }
      else if (mid < num) {
        morepq.push(num);
      }
      else {
        morepq.push(mid);
        mid = num;
      }
    }
    else if (lesspq.size() < morepq.size()) {
      if (mid < num) {
        lesspq.push(mid);
        morepq.push(num);
        mid = morepq.top();
        morepq.pop();
      }
      else {
        lesspq.push(num);
      }
    }
    else {
      if (mid < num) {
        morepq.push(num);
      }
      else {
        morepq.push(mid);
        lesspq.push(num);
        mid = lesspq.top();
        lesspq.pop();
      }
    }
    
    printf("%d\n", mid);
  }
}

/*
  알고리즘 수업 때 들었던 내용인데 까맣게 잊고 있었다.
  ~힙으로 중간값 트레이스하기~
*/