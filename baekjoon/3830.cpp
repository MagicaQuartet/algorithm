#include<cstdio>
#include<utility>
#define pii pair<int, int>
using namespace std;

int N, M, a, b, w;
int parents[100010];
int diff[100010];
char c;

int find(int node) {
  if (node == parents[node]) {
    return node;
  }

  int parent = find(parents[node]);
  diff[node] += diff[parents[node]];
  return parents[node] = parent;
}

void merge(int lhs, int rhs, int d) {
  int lhsRoot = find(lhs);
  int rhsRoot = find(rhs);

  if (lhsRoot != rhsRoot) {
    parents[lhsRoot] = rhsRoot;
    diff[lhsRoot] = diff[rhs] - diff[lhs] + d;  // 새로운 child가 된 lhsRoot의 diff를 lhs, rhs의 diff로 계산
  }
}

int main() {
  while (1) {
    scanf("%d %d", &N, &M);
    if (N == 0 && M == 0) {
      break;
    }

    for (int i=1; i<=N; i++) {
      parents[i] = i;
      diff[i] = 0;
    }
    
    for (int i=0; i<M; i++) {
      getchar();
      scanf("%c %d %d", &c, &a, &b);
      if (c == '!') {
        scanf("%d", &w);
        merge(a, b, w);
      }
      else {
        int aRoot = find(a);
        int bRoot = find(b);

        if (aRoot != bRoot) {
          printf("UNKNOWN\n");
        }
        else {
          printf("%d\n", diff[a]-diff[b]);
        }
      }
    }
  }
}