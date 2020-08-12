#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<limits>
#define ll long long
using namespace std;

int N, H;
ll H1[500010], H2[500010];

int main() {
  scanf("%d %d", &N, &H);
  memset(H1, 0, sizeof(H1));
  memset(H2, 0, sizeof(H2));

  for (int i=0; i<N; i++) {
    int area;
    scanf("%d", &area);
    if (i%2) {
      H1[area]++;
    }
    else {
      H2[H-area+1]++;
    }
  }

  for (int h=2; h<=H; h++) {
    H1[H-h+1] += H1[H-h+2];
    H2[h] += H2[h-1];
  }

  ll minVal = numeric_limits<ll>::max();
  int minCnt = 0;

  for (int i=1; i<=H; i++) {
    if (minVal >= H1[i]+H2[i]) {
      minCnt = (minVal == H1[i]+H2[i]) ? minCnt+1 : 1;
      minVal = H1[i]+H2[i];
    }
  }

  printf("%lld %d\n", minVal, minCnt);
}

/*
  알고리즘 분류에는 정렬, 이분 탐색으로 나와있는데 그냥 부분합으로 쉽게 풀 수 있음
*/