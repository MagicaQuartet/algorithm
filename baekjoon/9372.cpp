#include<cstdio>
int main(){int T,N,M,a,b;scanf("%d",&T);while(T--){scanf("%d%d",&N,&M);while(M--)scanf("%d%d",&a,&b);printf("%d\n",--N);}}

/*
MST 문제 절대 아님. 관련 알고리즘으로 풀 수야 있지만... 대충 생각해도 나라 수-1이 답이라는 것을 쉽게 떠올릴 수 있다.
 */