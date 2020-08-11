#include<cstdio>
#include<algorithm>
using namespace std;
int N, S;
int nums[100010];

int main() {
  scanf("%d %d", &N, &S);
  for (int i=0; i<N; i++) {
    scanf("%d", nums+i);
  }

  int i, j, sum;
  int minLen = 987654321;
  i = j = 0;
  sum = nums[i];

  while(j < N) {
    if (sum >= S) {
      minLen = min(minLen, j-i+1);
    }

    if (i == j) {
      j++;
      sum += nums[j];
    }
    else if (sum < S) {
      j++;
      sum += nums[j];
    }
    else {
      sum -= nums[i];
      i++;
    }
  }
  printf("%d\n", minLen < 987654321 ? minLen : 0);
}