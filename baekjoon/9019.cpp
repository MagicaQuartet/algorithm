#include<cstring>
#include<iostream>
#include<queue>
#include<string>
#include<utility>
using namespace std;
#define INF 10000
typedef pair<int, string> pis;
int T, A, B;

int D(int num) {
  return (num*2)%INF;
}

int S(int num) {
  return (num+9999)%INF;
}

int L(int num) {
  return ((num*10)+(num/1000))%INF;
}

int R(int num) {
  return (num/10)+(num%10)*1000;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--) {
    string ans;
    cin >> A >> B;
    queue<pis> q;
    int visited[10010];
    memset(visited, 0, sizeof(visited));
    q.push(make_pair(A, ""));
    while (1) {
      int num = q.front().first;
      string str = q.front().second;
      int len = str.size();
      q.pop();
      int d = D(num);
      string ds = str + "D";
      int s = S(num);
      string ss = str + "S";
      int l = L(num);
      string ls = str + "L";
      int r = R(num);
      string rs = str + "R";
      if (d == B) {
        ans = ds;
        break;
      }
      if (s == B) {
        ans = ss;
        break;
      }
      if (l == B) {
        ans = ls;
        break;
      }
      if (r == B) {
        ans = rs;
        break;
      }
      if (!visited[d]) {
        visited[d] = 1;
        q.push(make_pair(d, ds));
      }
      if (!visited[s]) {
        visited[s] = 1;
        q.push(make_pair(s, ss));
      }
      if (!visited[l] && !((len >= 1 && str[len-1] == 'R') && (len >= 2 && str[len-1] == 'L' && str[len-2] == 'L'))) {
        visited[l] = 1;
        q.push(make_pair(l, ls));
      }
      if (!visited[r] && !((len >= 1 && str[len-1] == 'L') && (len >= 2 && str[len-1] == 'R' && str[len-2] == 'R'))) {
        visited[r] = 1;
        q.push(make_pair(r, rs));
      }
    }
    cout << ans << "\n";
  }
}
