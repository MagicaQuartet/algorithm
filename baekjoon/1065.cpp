#include<iostream>

using namespace std;

int findHansu(int N, int current, int step, int mode) {
  if (current > N)
    return 0;
  
  int ret = 0;
  
  if (mode) {
    if ((current%10)+step > 9 || (current%10)+step < 0)
      ret = 1;
    else
      ret = 1 + findHansu(N, current*10+((current%10)+step), step, 1);
  }
  else { 
    ret = 1;
    for (int i=-9; i<9; i++) {
      if (current+i > 9 || current+i < 0)
        continue;
      ret += findHansu(N, current*10+(current+i), i, 1);
    }
  }

  return ret;
}

int main() {
  int N, ans;
  cin.sync_with_stdio(false);
  
  cin >> N;
  
  ans = 0;
  for (int i=1; i<10; i++)
      ans += findHansu(N, i, 0, 0);
  cout << ans << endl;
  return 0;
}

/* N이하의 1~9로 시작하는 모든 한수를 재귀 함수로 탐색 */