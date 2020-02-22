#include<cstdio>
#include<algorithm>
using namespace std;
int N, M, package[50], single[50];
int main() {
  scanf("%d %d", &N, &M);
  for (int i=0; i<M; i++) {
    scanf("%d %d", package+i, single+i);
  }
  sort(package, package+M);
  sort(single, single+M);
  
  printf("%d\n", (package[0] < single[0]*6 ? package[0]*(N/6) : single[0]*6*(N/6)) + (package[0] < single[0]*(N%6) ? package[0] : single[0]*(N%6)));
}

/*
  6개 단위로 살 때 가장 저렴한 경우의 값과 6으로 나눈 나머지를 살 때 가장 저렴한 경우의 값을 더한다.
  이 때 두 경우는 서로 다른 패키지일 수 있다. 참고로 한 브랜드 당 한 패키지만 살 수 있나 했는데 그건 아니었다.
*/