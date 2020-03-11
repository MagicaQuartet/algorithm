#include<iostream>
#include<string>
using namespace std;
int N, bonus, ans;
string s;
int main() {
  cin >> N >> s;
  
  ans = bonus = 0;
  for (int i=0; i<N; i++) {
    if (s[i] == 'O') {
      ans += (i+1) + bonus;
      bonus++;
    }
    else {
      bonus = 0;
    }
  }
  printf("%d\n", ans);
}