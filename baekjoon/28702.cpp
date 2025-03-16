#include<iostream>
#include<string>
using namespace std;
string S;
int to_num(string s) {
  if (s[0] >= '1' && s[0] <= '9') {
    int ret = 0;
    for (auto c: s) {
      ret = ret*10+(c-'0');
    }
    return ret;
  }
  return -1;
}
void to_str(int i) {
  if (i%3 == 0 && i%5 == 0) {
    printf("FizzBuzz\n");
  }
  else if (i%3==0) {
    printf("Fizz\n");
  }
  else if (i%5==0) {
    printf("Buzz\n");
  }
  else {
    printf("%d\n", i);
  }
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int to_numed = -1;
  for (int i=0; i<3; i++) {
    cin >> S;
    if (to_numed != -1) {
      continue;
    }
    int _to_numed = to_num(S);
    if (_to_numed == -1) {
      continue;
    }
    to_numed = to_num(S)+3-i;
  }
  to_str(to_numed);
}
