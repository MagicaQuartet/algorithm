#include<cstdio>
#include<cmath>
int x[21], y[21];
int T, N;
double solve(int idx, int cnt, int sumx, int sumy) {
  if (N/2-cnt > N-idx) {
    return -1.0;
  }
  if (idx >= N) {
    return sqrt((double)sumx*sumx+(double)sumy*sumy);
  }
  if (cnt == N/2) {
    return solve(idx+1, cnt, sumx+x[idx], sumy+y[idx]);
  }
  double ret1 = solve(idx+1, cnt, sumx+x[idx], sumy+y[idx]);
  double ret2 = solve(idx+1, cnt+1, sumx-x[idx], sumy-y[idx]);
  if (ret1 < 0 && ret2 < 0) {
    return -1.0;
  }
  else if (ret1 < 0) {
    return ret2;
  }
  else if (ret2 < 0) {
    return ret1;
  }
  return ret1 < ret2 ? ret1 : ret2;
}
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
      scanf("%d %d", &x[i], &y[i]);
    }
    printf("%.7f\n", solve(0, 0, 0, 0));
  }
}
