#include<iostream>
#include<vector>

using namespace std;

int main() {
  int T, N, temp;
  
  cin >> T;
  
  while (T--) {    
    cin >> N;
    
    int *foo = new int[N];
    int *visited = new int[N];
    int cnt=0;
    
    for (int i=0; i<N; i++) {
      cin >> temp;
      foo[i] = temp-1;
      visited[i] = 0;
    }
    
    for (int i=0; i<N; i++) {
      if (!visited[i]) {
        int step = i;
        
        while (!visited[step]) {
          visited[step] = 1;
          step = foo[step];
        }
        
        cnt++;
      }
    }
    
    cout << cnt << endl;
    
    delete foo;
    delete visited;
  }
  
  return 0;
}

/* 그냥 쭉 따라가면서 사이클 찾으면 됨 */