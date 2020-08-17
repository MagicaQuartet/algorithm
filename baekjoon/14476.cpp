#include<cstdio>
#include<algorithm>
using namespace std;

int N, maxGCD, removedNum;
int nums[1000010];
int gcdLR[1000010];
int gcdRL[1000010];

int getGCD(int a, int b) {
  return b ? getGCD(b, a%b) : a;
}

int main() {
  scanf("%d", &N);

  for (int i=1; i<=N; i++) {
    scanf("%d", nums+i);
  }

  gcdLR[1] = nums[1];
  gcdRL[N] = nums[N];

  for (int i=2; i<=N; i++) {
    gcdLR[i] = getGCD(gcdLR[i-1], nums[i]);
    gcdRL[N-i+1] = getGCD(gcdRL[N-i+2], nums[N-i+1]);
  }

  int maxGCD = -1, removedNum;
  int gcd = gcdRL[2];
  if (nums[1]%gcd) {
    maxGCD = gcd;
    removedNum = nums[1];
  }
  for (int i=2; i<N; i++) {
    int gcd = getGCD(gcdLR[i-1], gcdRL[i+1]);
    if (nums[i]%gcd && maxGCD < gcd) {
      maxGCD = gcd;
      removedNum = nums[i];
    }
  }
  gcd = gcdRL[N-1];
  if (nums[N]%gcd && maxGCD<gcd) {
    maxGCD = gcd;
    removedNum = nums[N];
  }

  if (maxGCD > -1) {
    printf("%d %d\n", maxGCD, removedNum);
  }
  else {
    printf("-1\n");
  }
}