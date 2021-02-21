#include<cstdio>
#include<algorithm>
using namespace std;
int num, sum, minVal;
int main() {
  sum = 0;
  minVal = 101;
  for (int i=0; i<7; i++) {
    scanf("%d", &num);
    if (num%2) {
      sum += num;
      minVal = min(minVal, num);
    }
  }
  if (sum == 0) {
    printf("-1\n");
  }
  else {
    printf("%d\n%d\n", sum, minVal);
  }
}