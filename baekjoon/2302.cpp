#include<cstdio>
#include<cstring>
int N, M, vip, pos, sum, f, fibo[41];
int getFibo(int idx){
  if (fibo[idx]!=-1) return fibo[idx];
  for(int i=f+1; i<=idx; i++){
    fibo[i] = fibo[i-1]+fibo[i-2];
    f=i;
  }
  return fibo[idx];
}
int main(){
  scanf("%d %d", &N, &M);
  pos = 1;
  sum = 1;
  memset(fibo, -1, 164);
  fibo[0] = fibo[1] = 1;
  fibo[2] = 2;
  f = 2;
  while(M--){
    scanf("%d", &vip);
    sum *= getFibo(vip-pos);
    pos = vip+1;
  }
  sum *= getFibo(N-pos+1);
  printf("%d\n", sum);
}

/* Note: 이 코드는 화상키보드로 작성되었습니다...! 하... */
/* VIP를 기준으로 분리된 각 영역에 대해서 길이 1, 2의 좌석으로 채우는 경우의 수를 모두 곱하면 된다 */