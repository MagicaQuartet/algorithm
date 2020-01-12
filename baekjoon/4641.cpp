#include<cstdio>
#include<cstring>
int main() {
  int arr[100], num, cnt = 0;
  memset(arr, 0, 400);
  while (1) {
    scanf("%d", &num);
    if (num == -1) break;
    else if (num == 0) {
      memset(arr, 0, 400);
      printf("%d\n", cnt);
      cnt = 0;
      continue;
    }
    arr[num-1] = 1;
    if (num%2 == 0 && arr[num/2-1] == 1) cnt++;
    if (num*2 < 100 && arr[num*2-1] == 1) cnt++;
  }
}