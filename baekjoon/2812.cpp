#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int N, K, cnt[10];
string num;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K >> num;
  memset(cnt, 0, sizeof(cnt));
  
  for (int i=0; i< N; i++) {
    cnt[num[i]-'0']++;
  }
}