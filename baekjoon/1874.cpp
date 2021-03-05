#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int N, visited[100010];
vector<char> ans;
int main() {
  scanf("%d", &N);
  memset(visited, 0, sizeof(visited));
  int step = 0;
  int possible = 1;
  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    if (!possible) continue;
    while (step < num) {
      ans.push_back('+');
      step++;
    }
    for (int j=step; j>=num; j--) {
      if (j != num && !visited[j]) {
        possible = 0;
        break;
      }
      if (!visited[j]) {
        ans.push_back('-');
        visited[j] = 1;
      }
    }
  }
  if (possible) {
    for (char c: ans) {
      printf("%c\n", c);
    }
  }
  else {
    printf("NO\n");
  }
}