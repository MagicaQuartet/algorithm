#include<cstdio>
#include<algorithm>
using namespace std;
int N, L, data[1000], x, cnt;
int main() {
  scanf("%d %d", &N, &L);
  for (int i=0; i<N; i++) {
    scanf("%d", data+i);
  }
  sort(data, data+N);
  x = data[0] + L - 1;
  cnt = 1;
  
  for (int i=0; i<N; i++) {
    if (data[i] > x) {
      x = data[i] + L - 1;
      cnt++;
    }
  }
  printf("%d\n", cnt);
}

/*
  입력받은 배열을 오름차순 정렬하고 간단하게 이챠이챠 하면 된다.
*/