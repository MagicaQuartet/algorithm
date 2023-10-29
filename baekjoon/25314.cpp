#include<cstdio>
using namespace std;
int N;
int main() {
  scanf("%d", &N);
  for (int i=1; i*4 <= N; i++) {
    printf("long ");
  }
  printf("int\n");
}
