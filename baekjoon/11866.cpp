#include<cstdio>
#include<queue>
using namespace std;

int N, K, cnt;

int main() {
  scanf("%d %d", &N, &K);
  queue<int> q;
  vector<int> joseph;

  for (int i=1; i<=N; i++) {
    q.push(i);
  }

  cnt = 1;
  while(!q.empty()) {
    int num = q.front();
    q.pop();

    if (cnt%K) {
      q.push(num);
    }
    else {
      joseph.push_back(num);
    }

    cnt += 1;
  }

  printf("<");
  for (int i=0; i<N; i++) {
    printf("%d%s", joseph[i], (i < N-1) ? ", " : "");
  }
  printf(">\n");
}