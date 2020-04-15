#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
  int N, K, doll[510], partialSum[510];
  long double ave, ans = 250000000000;
  
  scanf("%d %d", &N, &K);
  
  partialSum[0] = 0;
  
  for (int i=1; i<=N; i++) {
    scanf("%d", doll+i);
  }
  
  for (int i=1; i<=N; i++) {
    partialSum[i] = doll[i] + partialSum[i-1];
  }
  
  for (int i=1; i<=N; i++) {
    for (int j=i+K-1; j<=N; j++) {
      long double sum = partialSum[j] - partialSum[i-1];
      ave = sum / (j-i+1);
      
      long double squareSum = 0;
      
      for (int k=i; k<=j; k++) {
        squareSum += (doll[k]-ave)*(doll[k]-ave);
      }
      
      ans = min(ans, squareSum / (j-i+1));
    }
  }
  
  printf("%.11Lf\n", sqrt(ans));
}

/*
  부분합을 제외하면 단순한 알고리즘이며 부분합을 쓰지 않아도 통과를 하는지는 확인하지 않았다.
  
  ** 나올 수 있는 답의 최댓값은 987654321보다 훨씬 크다!!!! **
*/