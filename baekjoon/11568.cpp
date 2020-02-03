#include<cstdio>
int N, data, len, cache[1000];
int main() {
  scanf("%d", &N);
  len = 1;
  for (int i=0; i<N; i++) {
    scanf("%d", &data);
    cache[i] = -1;
    for (int j=0; j<=i; j++) {
      if (cache[j] == -1 || data <= cache[j]) {
        cache[j] = data;
        if (len < j+1) {
          len = j+1;
        }
        break;
      }
    }
  }
  printf("%d\n", len);
}