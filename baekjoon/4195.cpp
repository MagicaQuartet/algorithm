#include<iostream>
#include<map>
#include<utility>
#include<string>
using namespace std;

int T, F, parent[100010], level[100010], size[100010], cnt;
string a, b;
map<string, int> m;

void init() {
  for (int i=0; i<100001; i++) {
    parent[i] = i;
    level[i] = 1;
    size[i] = 1;
  }
  
  m.clear();
  cnt = 0;
}

int find(int u) {
  if (u == parent[u]) {
    return u;
  }
  
  return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
  int r1 = find(u), r2 = find(v);
  
  if (r1 == r2) {
    return;
  }
  
  if (level[r1] > level[r2]) {
    swap(r1, r2);
  }
  
  parent[r1] = r2;
  
  if (level[r1] == level[r2]) {
    level[r2]++;
  }
  
  size[r2] += size[r1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> T;
  while (T--) {
    cin >> F;
    init();
    
    while(F--) {
      cin >> a >> b;

      if (m.count(a) == 0) {
        m[a] = cnt++;
      }
      if (m.count(b) == 0) {
        m[b] = cnt++;
      }

      merge(m[a], m[b]);
      printf("%d\n", size[find(m[a])]);
    }
  }
}

/*
  Union-Find
  
  경로 압축 구현을 어떻게 하는 건지 궁금했는데 너무나도 단순한 방법이었네
*/