#include<cstdio>
using namespace std;

int n;
int main() {
  scanf("%d", &n);
  printf("%d\n", n%7 == 2 ? 1 : 0);
}
