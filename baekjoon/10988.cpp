#include<iostream>
#include<string>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  int len, p;
  cin >> s;
  
  len = s.size();
  p = 1;
  for (int i=0; i<len; i++) {
    if (i > len-1-i) {
      break;
    }
    
    if (s[i] != s[len-1-i]) {
      p = 0;
      break;
    }
  }
  printf("%d", p);
}