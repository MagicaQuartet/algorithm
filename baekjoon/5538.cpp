#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int cntJ, cntO, cntI, ans;
string str;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  
  cin >> str;
  cntJ = cntO = cntI = ans = 0;
  
  for (auto c : str) {
    if (c == 'J') {
      if (cntO > 0 || cntI > 0) {
        cntJ = cntO = cntI = 0;
      }
      cntJ++;
    }
    else if (c == 'O') {
      if (cntI > 0 || cntJ == cntO) {
        cntJ = cntO = cntI = 0;
      }
      else {
        cntO++;
      }
    }
    else if (c == 'I') {
      cntI++;
      if (cntO <= cntI) {
        ans = max(ans, min(cntJ, min(cntO, cntI)));
      }
    }
  }
  printf("%d\n", ans);
}

/*
  cstdio를 사용하는 게 iostream을 쓰는 것보다 항상 좋은 줄 알았는데 iostream 쪽이 더 빨랐다.
  물론 입력 방식 상에서의 차이인지 이후 처리 과정에서의 차이인지는 모르겠다.
  
  전체 문자열을 받아놓고 처리를 해서 입력 횟수가 적어서 그런가? 대신 메모리를 더 많이 쓰긴 했다.
  cstdio로 하나하나 입력받으면 1112KB에 20ms가 나왔다.
*/