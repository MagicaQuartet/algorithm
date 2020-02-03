#include<cstdio>
int N;
long long ans;
void solve(int prev, int len, long long result) {
  if (N < 0) {
    return;
  }
  if (len == 1) {
    if (N == 0) {
      ans = result;
    }
    N--;
    return;
  }
  
  for (int i=0; i<prev; i++) {
    solve((prev==10 && i==0 ? 10 : i), len - 1, (prev==10 && i==0 ? 0 : 10*result+i));
  }
}
int main() {
  scanf("%d", &N);
  ans = -1;
  solve(10, 11, 0);
  printf("%lld\n", ans);
}

/* 초안: 효율 생각 안하고 일단 모든 경우의 수를 오름차순으로 구하되 k-1번째까지는 결과를 저장/출력하지 않고 k번째 수만 골라낸 다음 그 뒤로는 모두 제껴버리는 방법을 사용했음 */
/* ???근데 이게 2등이네 */