#include<cstdio>
int N, M, sum, ans;
int main() {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    sum += num+1;
  }
  
  ans = 0;
  if (sum < M) {
    int max = (M-sum-1)/(N+1)+1;
    int r = (M-sum) - (max-1)*(N+1);
    
    for (int i=1; i<=max; i++) {
      ans += i*i*(i==max ? r : N+1);
    }
  }
  printf("%d\n", ans);
}

/*
  주어진 약속들로 기분을 0 이상의 정수로 최대 몇일이나 유지할 수 있는지 구한다.
  커버하지 못하는 날을 약속 사이사이에 균등하게 분배하고 그 때의 우울함을 구하면 된다.
*/