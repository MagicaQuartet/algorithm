#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int num[50], temp, idx;
string exp;
int main() {
  cin.sync_with_stdio(false);
  cin >> exp;
  
  memset(num, 0, 4*exp.size());
  temp = 0;
  idx = 0;
  
  for (auto c : exp) {
    if (c == '-') {
      num[idx++] += temp;
      temp = 0;
    }
    else if (c == '+') {
      num[idx] += temp;
      temp = 0;
    }
    else {
      temp = 10*temp + (c-'0');
    }
  }
  num[idx] += temp;
  
  temp = num[0];
  for (int i=1; i<=idx; i++) {
    temp -= num[i];
  }
  cout << temp << endl;
}

/*
식의 길이가 최대 50이면 num 배열 크기를 30으로 잡아도 되는거 아닌가?? 모르겠다...
*/