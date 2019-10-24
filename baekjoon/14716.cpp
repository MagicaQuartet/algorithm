#include <cstdio>
#include <vector>

using namespace std;

int search(vector<vector<int>>& map, int i, int j) {
  if (map[i][j] == 0)
    return 0;
  
  map[i][j] = 0;
  if (i > 0) {
    search(map, i-1, j);
    if (j > 0)
      search(map, i-1, j-1);
    if (j < map[0].size()-1)
      search(map, i-1, j+1);
  }
  if (i < map.size()-1) {
    search(map, i+1, j);
    if (j > 0)
      search(map, i+1, j-1);
    if (j < map[0].size()-1)
      search(map, i+1, j+1);
  }
  if (j > 0) {
    search(map, i, j-1);
    if (i > 0)
      search(map, i-1, j-1);
    if (i < map.size()-1)
      search(map, i+1, j-1);
  }
  if (j < map[0].size()-1) {
    search(map, i, j+1);
    if (i > 0)
      search(map, i-1, j+1);
    if (i < map.size()-1)
      search(map, i+1, j+1);
  }
  
  return 0;
}

int main() {
  int M, N, input;
  int answer = 0;
  vector<vector<int>> map;
  
  scanf("%d %d", &M, &N);
  
  for (int i=0; i<M; i++) {
    map.push_back(vector<int>());
    for (int j=0; j<N; j++) {
      scanf("%d", &input);
      map[i].push_back(input);
    }
  }
  
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      if (map[i][j] == 1) {
        answer += 1;
        search(map, i, j);
      }
    }
  }
  
  printf("%d\n", answer);
  return 0;
}

/* 한 번 확인한 자리는 항상 0이 되도록 하며 탐색 */