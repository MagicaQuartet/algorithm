#include<cstdio>
int main() {
  int N, M, J, pos, apple, cnt;
  scanf("%d %d %d", &N, &M, &J);
  cnt = 0;
  pos = 1;
  for (int i=0; i<J; i++) {
    scanf("%d", &apple);
    if (apple < pos) {
      cnt += pos - apple;
      pos = apple;
    }
    else if (apple > pos+M-1) {
      cnt += apple - (pos+M-1);
      pos = apple - M+1;
    }
  }
  printf("%d", cnt);
}