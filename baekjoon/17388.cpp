#include<cstdio>
#include<algorithm>
using namespace std;
int s, k, h;
int main() {
  scanf("%d %d %d", &s, &k, &h);
  if (s+k+h >= 100) {
    printf("OK");
  }
  else {
    int _min = min(s, min(k, h));
    if (_min == s) {
      printf("Soongsil");
    }
    else if (_min == k) {
      printf("Korea");
    }
    else {
      printf("Hanyang");
    }
  }
}