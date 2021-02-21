#include<cstdio>
#include<cstring>
int N, arr[50];
int fibo(int n) {
  if (arr[n] != -1) {
    return arr[n];
  }
  return arr[n] = fibo(n-2) + fibo(n-1);
}
int main() {
  scanf("%d", &N);
  memset(arr, -1, sizeof(arr));
  arr[0] = 0;
  arr[1] = 1;
  printf("%d\n", fibo(N));
}