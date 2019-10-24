#include <cstdio>

using namespace std;

int main() {
  char c;
  int A = 0, B = 0;
  while((c=getchar()) != EOF) {
    if (c >= 49 && c <= 57) {
      if (A == 0)
        A = c - 48;
      else
        B = c - 48;
    }
    
    if (A > 0 && B > 0) {
      printf("%d\n", A+B);
      A = 0;
      B = 0;
    }
  }
  return 0;
}

/* 테스트 케이스의 끝을 나타내는 표시가 따로 없으므로 char 하나씩 입력받으며 EOF인지 아닌지 확인한다 */