#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int x, y, w, h;
int main() {
  scanf("%d %d %d %d", &x, &y, &w, &h);
  printf("%d\n", min(min(x, y), min(w-x, h-y)));
}