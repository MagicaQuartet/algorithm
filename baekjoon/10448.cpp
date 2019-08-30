#include<cstdio>
#include<vector>

using namespace std;

int main() {
  int T, K;
  scanf("%d", &T);
  
  while (T--) {
    int cnt;
    vector<int> foo;
    
    scanf("%d", &K);
    
    for (int i=1; i*(i+1)/2 <= K-2; i++) {
      foo.push_back(i*(i+1)/2);
      cnt = i;
    }
    
    int check = 0;
    
    for (int i=cnt-1; i>=0; i--) {
      for (int j=i; j>=0; j--) {
        for (int k=j; k>=0; k--) {
          if (foo[i]+foo[j]+foo[k] == K) {
            check = 1;
            break;
          }
        }
        
        if (check)
          break;
      }
      
      if (check)
        break;
    }
    
    printf("%d\n", check);
  }  
  
  return 0;
}

/* K 이하의 삼각수를 구한 뒤 브루트 포스 */