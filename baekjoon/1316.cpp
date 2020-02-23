#include<iostream>
#include<cstring>
using namespace std;
int N, cnt, visited[26];
char pre;
string s;
int main() {
  cin.sync_with_stdio(false);
  cin >> N;
  cnt = N;
  while (N--) {
    cin >> s;
    memset(visited, 0, sizeof(visited));
    pre = 0;
    
    for (char c : s) {
      if (c != pre && visited[c-'a']) {
        cnt--;
        break;
      }
      
      visited[c-'a']++;
      pre = c;
    }
  }
  cout << cnt;
}