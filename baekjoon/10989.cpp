#include<cstdio>
#include<cstring>
int N, cnt[10000];
int main() {
  memset(cnt, 0, sizeof(cnt));
  scanf("%d", &N);
  
  while(N--) {
    int num;
    scanf("%d", &num);
    cnt[num-1]++;
  }
  
  for (int i=0; i<10000; i++) {
    for (int j=0; j<cnt[i]; j++) {
      printf("%d\n", i+1);
    }
  }
}

/*
  입력의 범위가 1~10000이길래 카운팅 소트를 써봤다.
  그냥 다 받고 정렬 돌리면 메모리 초과되려나?
*/