#include<cstdio>
#include<algorithm>
using namespace std;
int N, M, ret, sum, mars[1000][1000], prevCache[1000], nextCache[1000];
int main() {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%d", &mars[i][j]);
    }
  }
  for (int i=0; i<M; i++) {
      prevCache[i] = 0;
    }
  
  if (N == 1) {
    ret = 0;
    for (int i=0; i<M; i++) {
      ret += mars[0][i];
    }
  }
  else {
    // bottom
    sum = 0;
    for (int i=M-1; i>=0; i--) {
      sum += mars[N-1][i];
      prevCache[i] = sum;
    }

    // mid
    for (int i=N-2; i>0; i--) {
      for (int j=0; j<M; j++) {
        sum = mars[i][j];
        ret = -100000000;
        for (int k=j-1; k>=0; k--) {
          sum += mars[i][k];
          ret = max(ret, sum+prevCache[k]);
        }

        sum = 0;
        for (int k=j; k<M; k++) {
          sum += mars[i][k];
          ret = max(ret, sum+prevCache[k]);
        }

        nextCache[j] = ret;
      }

      for (int j=0; j<M; j++) {
        prevCache[j] = nextCache[j];
      }
    }

    // top
    sum = 0;
    ret = -100000000;
    for (int i=0; i<M; i++) {
      sum += mars[0][i];
      ret = max(ret, sum+prevCache[i]);
    }
  }
  printf("%d\n", ret);
}

/* 처음에는 2차원 dp 배열로 top-down을 시도하였으나 시간 초과로 실패했다. 단순 시간복잡도 계산 만으로는 충분해 보였는데 어디가 문제였을까..? */
/* 그래서 1차원 dp 배열을 이용한 bottom-up 방식으로 바꾸었더니 통과는 하였다. 그런데 여전히 속도는 끔찍하게 느리고 그 원인을 잘 모르겠다.. */

/* 추가) 우선 위 코드에서 3중 for-loop으로 구현된 부분을 2중 for-loop으로 구현이 가능하다. */
/* https://www.acmicpc.net/source/8254814 여기에 이해하기 쉽게 구현이 되어있으니 참고 */