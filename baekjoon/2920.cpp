#include<cstdio>
int num, prev, diff;
int main() {
  prev = 0;
  diff = 0;
  for (int i=0; i<8; i++) {
    scanf("%d", &num);
    if (prev > 1) {
      if (num-prev > 1 || num-prev < -1 || (diff != 0 && diff != num-prev)) {
        printf("mixed\n");
        return 0;
      }
      diff = num - prev;
    }    
    prev = num;
  }
  printf("%s\n", diff == 1 ? "ascending" : "descending");
}