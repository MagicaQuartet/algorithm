#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string S;
int cnt[30];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> S;
  memset(cnt, 0, sizeof(cnt));
  for (auto c: S) {
    cnt[c-'a']++;
  }
  for (char i=0; 'a'+i<='z'; i++) {
    printf("%d ", cnt[i]);
  }
  printf("\n");
}
