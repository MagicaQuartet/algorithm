#include<cstdio>
#include<vector>
using namespace std;
bool result(int _a, int _b, int _strike, int _ball) {
  int strike = 0, ball = 0;
  vector<int> a, b;
  a.push_back(_a%10);
  a.push_back((_a/10)%10);
  a.push_back(_a/100);
  b.push_back(_b%10);
  b.push_back((_b/10)%10);
  b.push_back(_b/100);
  
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (a[i]==b[j]) {
        if (i==j) {
          strike++;
        }
        else {
          ball++;
        }
      }
    }
  }

  return (strike==_strike && ball==_ball);
}

int main() {
  int T, cnt;
  vector<int> candidates;
  scanf("%d", &T);
  
  for (int i=1; i<10; i++) {
    for(int j=1; j<10; j++) {
      for(int k=1; k<10; k++) {
        if (i!=j && j!=k && k!=i) {
          candidates.push_back(100*i + 10*j + k);
        }
      }
    }
  }
  
  while(T--) {
    int q, s, b;
    scanf("%d %d %d", &q, &s, &b);
    
    for (int i=0; i<candidates.size(); i++) {
      if (candidates[i] == -1) {
        continue;
      }
      
      if (!result(candidates[i], q, s, b)) {
        candidates[i] = -1;
      }
    }
  }
  
  cnt = 0;
  
  for (int i=0; i<candidates.size(); i++) {
    if (candidates[i] != -1) {
      cnt++;
    }
  }
  
  printf("%d\n", cnt);
}

/** 효율성은 전혀 고려하지 않은 풀이이다. */
/** 다른 사람들은 일단 쿼리를 다 받고, 세 자리 수를 생성함과 동시에 그때그때 체크를 한다. 그거 괜찮네.. */