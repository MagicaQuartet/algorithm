#include<cstdio>
using namespace std;
int N;
int main() {
  scanf("%d", &N);
  printf("%d\n", (N/10 == N%10) ? 1 : 0);
}
