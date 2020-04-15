#include<cstdio>
#include<cstring>
int N, L, A, B, parent[300010], visited[300010];

int find(int a) {
  if (parent[a] == a) {
    return a;
  }
  
  return parent[a] = find(parent[a]);
}

bool add(int a, int b) {
  int ra = find(a);
  int rb = find(b);
  
  if (!visited[a]) {
    visited[a] = 1;
    parent[a] = b;
    return true;
  }
  else if (!visited[b]) {
    visited[b] = 1;
    return true;
  }
  else if (a == b) {
    return false;
  }
  else if (add(ra, ra)) {
    parent[a] = b;
    return true;
  }
  else if (add(rb, rb)) {
    parent[b] = b;
    return true;
  }
  else {
    return false;
  }
}

int main() {
  scanf("%d %d", &N, &L);
  memset(visited, 0, 4*(L+1));
  
  for (int i=1; i<=L; i++) {
    parent[i] = i;
  }
  
  for (int i=0; i<N; i++) {
    scanf("%d %d", &A, &B);
    
    printf("%s\n", add(A, B) ? "LADICA" : "SMECE");
  }
}