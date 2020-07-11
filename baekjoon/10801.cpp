#include<cstdio>

int A[10], B[10], cnt;

int main() {
  for (int i=0; i<10; i++) {
    scanf("%d", A+i);
  }
  for (int i=0; i<10; i++) {
    scanf("%d", B+i);
  }
  
  cnt = 0;
  for (int i=0; i<10; i++) {
    if (A[i] > B[i]) {
      cnt++;
    }
    else if (A[i] < B[i]) {
      cnt--;
    }
  }
  
  printf("%c\n", cnt > 0 ? 'A' : (cnt < 0 ? 'B' : 'D'));
}