#include<cstdio>
int num, max=0, idx;
int main() {
  for (int i=0; i<9; i++) {
    scanf("%d", &num);
    if (max < num){
      idx = i+1;
      max = num;
    }    
  }
  printf("%d\n%d\n", max, idx);
}