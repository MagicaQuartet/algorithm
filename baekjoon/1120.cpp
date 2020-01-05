#include<cstdio>
#include<cstring>
int main() {
  char A[51], B[51];
  int ret = 50;
  scanf("%s %s", A, B);
  for (int i=0; i<strlen(B) - strlen(A) + 1; i++) {
    int _ret = 0;
    for (int j=0; j<strlen(A); j++)
      if (A[j] != B[i+j])
        _ret++;
    ret = ret < _ret ? ret : _ret;
  }
  printf("%d\n", ret);
  return 0;
}

/* B 위에서 A를 이리저리 옮겨봤을 때 겹치는 영역의 차이가 가장 작은 곳을 찾는다. 그 영역에서의 차이가 문제의 답이다. */
/* 여담으로, 앞으로는 문자열 관련 문제를 풀면 다른 사람들이 어떻게 풀었는지 꼭 보도록 하자 */