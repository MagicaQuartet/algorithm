#include<cstdio>
#include<cstring>
using namespace std;
char A[1001], B[1001];
int cache[1001], j, curr;
int main() {
  memset(cache, 0, 4*1001);
  scanf("%s %s", A, B);
  for (int i=0; A[i]!=0; i++) {
    curr = 0;
    for (j=0; B[j]!=0; j++) {
      if (cache[j] > curr) {
        curr = cache[j];
      }
      else if (A[i]==B[j]) {
        cache[j] = curr+1;
      }
    }
  }
  curr = 0;
  for (int k=0; k<j; k++) {
    if (cache[k] > curr) {
      curr = cache[k];
    }
  }
  printf("%d\n", curr);
}

/* 완벽히 이해를 하지 않은 채로 풀은 느낌이니 다시 이해해보도록 하자. */
/* 그리고 메모리를 어떻게 1MB만 쓰고 이걸 풀 수 있지?? */

/* 수정) amatuer789님 코드 보고 이해했다... 해결 못했던 다른 DP문제에도 적용 가능한 기법일 듯함 */
/* 마지막 loop는 두 string의 길이가 달라 1차원 cache에 정보가 충분히 들어가지 않았을 경우에 필요 */
/* 그래도 기본 풀이 먼저 이해하는 것이 중요 */