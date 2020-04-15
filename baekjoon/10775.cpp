#include<cstdio>
#include<cstring>
#include<utility>
using namespace std;
int G, P, g, parent[100010], size[100010];

int find(int u) {  
  if (parent[u] == u || parent[u] == -1) {
    return parent[u];
  }
  
  return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
  int r1 = find(u);
  int r2 = find(v);
  
  if (parent[r1] == parent[r2]) {
    return;
  }
  
  if (r1 < r2) {
    swap(r1, r2);
  }
  
  parent[r1] = r2;  
  size[r2] += size[r1];
}

bool add(int u) {  
  int r = find(u);
  
  if (r == -1) {
    r = parent[u] = u;
    size[u] = 1;
  }
  else if (r > 1) {
    add(r-1);
  }
  else {
    return false;
  }
  
  if (r > 1 && find(r-1) != -1) {
    merge(r, parent[r-1]);
  }
  
  if (r < G && find(r+1) != -1) {
    merge(r, parent[r+1]);
  }
  
  return true;
}

int count() {
  int ret = 0;
  for (int i=1; i<=G; i++) {
    if (parent[i] == i) {
      ret += size[i];
    }
  }
  return ret;
}

int main() {
  scanf("%d %d", &G, &P);
  memset(parent, -1, 4*(G+1));
  bool valid = true;
  
  for (int i=0; i<P; i++) {
    scanf("%d", &g);
    
    if (valid) {
      valid = add(g);
    }
  }
  
  printf("%d\n", count());
}

/*
  Union-find
  
  입력을 받을 때마다 가능한 가장 큰 번호의 게이트를 배정한다고 가정하고, 배정된 게이트 중 번호가 연속된 것들을 한 그룹으로 묶는다.
  
  이때, 편의를 위해 루트는 항상 그룹에서 가장 작은 번호가 되도록 한다. 랭크 최적화를 하지 않아도 통과하니 괜찮다.
  
  시나리오는 다음과 같다. parent[u] != -1일 경우 경로 압축이 되었을 때를 가정한다.
  add(u)
    (parent[u] == -1일 경우)
      한 그룹이 u에 인접한다면, u를 그 그룹에 더한다.
      두 그룹이 동시에 u에 인접한다면, 두 그룹을 합치고 u를 합쳐진 그룹에 더한다.
    (parent[u] != -1일 경우)
      parent[u]이 1이면, 더 이상 게이트를 배정할 수 없다. 이제부터는 입력을 받기만 하고 별도의 연산은 하지 않는다.
      parent[u]이 2 이상이면, add(parent[u]-1) 실행
  
  답을 구할 때는 parent[u] == u 인 u의 size[u]를 합한다.
*/