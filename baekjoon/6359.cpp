#include<cstdio>
#include<cstring>
int T, n, cnt, room[100];
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    memset(room, 0, n*4);
    cnt = 0;
    for (int i=1; i<=n; i++) {
      for (int j=i; j<=n; j+=i) {
        room[j-1] = !room[j-1];
      }
    }
    for (int i=0; i<n; i++) {
      if (room[i]==1) cnt++;
    }
    printf("%d\n", cnt);
  }
}