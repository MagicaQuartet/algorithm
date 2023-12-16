#include<cstdio>
using namespace std;
#define ll long long
int N;
ll reps[12] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111, 11111111111, 111111111111};
ll get() {
  int i = 0;
  int j = 0;
  int k = 0;
  for (int idx=1; idx<N; idx++) {
    if (i==j && j==k) {
      k++;
      i = 0;
      j = 0;
    }
    else if (i==j) {
      j++;
      i= 0;
    }
    else {
      i++;
    }
  }
  return reps[i]+reps[j]+reps[k];
}
int main() {
  scanf("%d", &N);
  printf("%lld\n", get());
}
