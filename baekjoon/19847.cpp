#include<cstdio>
#include<cstring>
#define ll long long
int N, step, firstNum, prevMin, arr[1000010];
ll prefixSum[1000010], sum;
int main(){
  scanf("%d", &N);
  prefixSum[0] = 0;
  scanf("%d", &firstNum);
  memset(arr, 0, sizeof(arr));
  prevMin = firstNum;
  for (int i=1; i<firstNum; i++) {
    prefixSum[i] = prefixSum[i-1] + i;
  }
  arr[firstNum-1] = 1;
  for (int i=1; i<N; i++) {
    int num;
    scanf("%d", &num);
    if (prevMin > num) {
      for (int j=num; j<prevMin; j++) {
        if (!arr[j]) continue;
        arr[num-1] += (j/num)*arr[j];
        arr[j%num] += arr[j];
        arr[j] = 0;
      }
      prevMin = num;
    }
  }
  sum = 0;
  for (int i=1; i<firstNum; i++) {
    sum += arr[i]*prefixSum[i];
  }
  printf("%.10lf\n", (double)sum/firstNum);
}
