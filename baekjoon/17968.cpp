#include<cstdio>

int n;
int fire[1005], check[1001];

int main() {
  scanf("%d", &n);
  
  fire[0] = fire[1] = 1;
  for (int i=2; i<=n; i++)   {
    for (int j=1; j<=n; j++) {
      check[j] = 1;
    }
    
    for (int k=1; i-2*k>=0; k++) {
      int val = fire[i-k] + (fire[i-k] - fire[i-2*k]);
      if (val <= 0) {
        continue;
      }
      
      check[val] = 0;
    }
    
    for (int j=1; j<=1001; j++) {
      if (check[j] == 1) {
        fire[i] = j;
        break;
      }
    }
  }
  
  printf("%d\n", fire[n]);
}