#include<iostream>
#include<string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  
  char prev = s[0];
  int length = 1;
  int cnt = 0;
  for (int i=1; i<s.size(); i++) {
    if (prev + 1 == s[i]) {
      length += 1;
    }
    else {
      if (length == 3) {
        cnt += 1;
      }
      length = 1;
    }
    prev = s[i];
  }
  if (length == 3) {
    cnt +=1;
  }
  printf("%d\n", cnt);
  return 0;
}

/* 간단하게 세도 된다 */