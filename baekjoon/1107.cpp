#include<cstdio>
#include<vector>

using namespace std;

int abs(int a, int b) {
  return a > b ? a - b : b - a;
}

int length(int a) {
  if (a < 10) { return 1; }
  else if (a < 100) { return 2; }
  else if (a < 1000) { return 3; }
  else if (a < 10000) { return 4; }
  else if (a < 100000) { return 5; }
  else { return 6; }
}

int push(const int N, const vector<int>& button, int cnt, int sum) {
  if (cnt == 6) {
    return sum;
  }
  
  int total_cnt = 500000;
  int ret = 0;
  
  for (int i=0; i<10; i++) {
    if (button[i] == 0) {
      continue;
    }
    
    int _ret = push(N, button, cnt+1, sum*10 + i);
    if (total_cnt > abs(N, _ret) + length(_ret)) {
      total_cnt = abs(N, _ret) + length(_ret);
      ret = _ret;
    }
  }
  
  if (cnt > 0 && total_cnt > abs(N, sum) + length(sum)) {
    ret = sum;
  }
  
  return ret;
}

int main() {
  int N, M, diff, ret, cnt;
  vector<int> button(10, 1);
  scanf("%d\n%d", &N, &M);
  
  for (int i=0; i<M; i++) {
    int broken;
    scanf("%d", &broken);
    button[broken] = 0;
  }
  
  diff = abs(N, 100);
  cnt = 0;
  
  if (M < 10) {
    ret = push(N, button, 0, 0);
    cnt += abs(N, ret) + length(ret);
  }
  else {
    cnt = diff;
  }

  printf("%d\n", diff < cnt ? diff : cnt);
}

/* 완전탐색 구현 시 각 단계에서 놓치는 경우가 없도록 하자 */