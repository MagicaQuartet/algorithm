#include<iostream>

using namespace std;

int main() {
  int N, M, candy;
  cin >> N >> M;
  
  int **map = new int*[N];
  
  for (int i=0; i<N; i++) {
    map[i] = new int[M];
    
    for (int j=0; j<M; j++) {
      cin >> candy;
      map[i][j] = candy;
    }
  }
  
  for (int i=1; i<N; i++) {
    map[i][0] += map[i-1][0];
  }
  for (int i=1; i<M; i++) {
    map[0][i] += map[0][i-1];
  }
  
  for (int i=1; i<N; i++) {
    for (int j=1; j<M; j++) {
      int max = map[i-1][j-1];
      if (max < map[i][j-1])
        max = map[i][j-1];
      if (max < map[i-1][j])
        max = map[i-1][j];
      
      map[i][j] += max;
    }
  }
  
  cout << map[N-1][M-1] << endl;
    
  return 0;
}

/* 간단한 2차원 Dynamic programming */