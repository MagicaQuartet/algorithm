#include<cstdio>

int N, num, ans;
int visited[1000010];

int main () {
  scanf("%d", &N);
  ans = 0;
  
  for (int i=0; i<=N; i++) {
    visited[i] = 0;
  }
  
  for (int i=0; i<N; i++) {
    scanf("%d", &num);
    
    visited[num] = visited[num-1]+1;
    if (ans < visited[num]) {
      ans = visited[num];
    }
  }
  
  printf("%d\n", N - ans);
}

/*
  LIS 문제인 줄 알았는데 아니었다..
  잘 생각해보면 움직이지 않는 아이들은 1씩 증가하는 가장 긴 수열에 포함되어있음을 떠올릴 수 있는데, 나는 왜 못할가...??
*/