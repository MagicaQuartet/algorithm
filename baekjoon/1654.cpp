#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

int K, N;
int arr[10010];

int main() {
  scanf("%d %d", &K, &N);
  for (int i=0; i<K; i++) {
    scanf("%d", arr+i);
  }
  sort(arr, arr+K);

  ll start = 1;
  ll end = arr[K-1];
  ll mid;
  while (start <= end) {
    mid = (start + end) / 2;
    if (start == end) break;
    
    int cnt = 0;
    for (int i=K-1; i>=0; i--) {
      cnt += arr[i]/mid;
    }

    if (cnt < N) {
      end = mid - 1;
    }
    else {
      if (start == mid) {
        cnt = 0;
        for (int i=K-1; i>=0; i--) {
          cnt += arr[i]/(mid+1);
        }
        if (cnt >= N) {
          mid += 1;
        }
        break;
      }
      start = mid;
    }
  }

  printf("%lld\n", mid);
}