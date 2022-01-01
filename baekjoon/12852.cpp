#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n, cnt[1000010], parent[1000010];
int main() {
  scanf("%d", &n);
  memset(cnt, -1, sizeof(cnt));
  memset(parent, -1, sizeof(parent));
  cnt[n] = 0;
  parent[n] = -1;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int num = q.front();
    q.pop();
    if (num == 1) {
      break;
    }
    if (num % 3 == 0 && (cnt[num/3] == -1 || cnt[num/3] > cnt[num] + 1)) {
      cnt[num/3] = cnt[num] + 1;
      parent[num/3] = num;
      q.push(num/3);
    }
    if (num % 2 == 0 && (cnt[num/2] == -1 || cnt[num/2] > cnt[num] + 1)) {
      cnt[num/2] = cnt[num] + 1;
      parent[num/2] = num;
      q.push(num/2);
    }
    if (cnt[num-1] == -1 || cnt[num-1] > cnt[num] + 1) {
      cnt[num-1] = cnt[num] + 1;
      parent[num-1] = num;
      q.push(num-1);
    }
  }
  printf("%d\n", cnt[1]);
  vector<int> ans;
  int num = 1;
  while (num != -1) {
    ans.push_back(num);
    num = parent[num];
  }
  for (int i=ans.size()-1; i>=0; i--) {
    printf("%d ", ans[i]);
  }
}
