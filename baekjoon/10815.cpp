#include<cstdio>
#include<algorithm>
using namespace std;

int N, M;
int arr[500010];

int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", arr+i);
  }
  sort(arr, arr+N);
  scanf("%d", &M);
  for (int i=0; i<M; i++) {
    int target;
    int start = 0;
    int end = N-1;
    int found = 0;
    scanf("%d", &target);
    
    while (start <= end) {
      int mid = (start + end) / 2;
      if (arr[mid] == target) {
        found = 1;
        break;
      }

      if (arr[mid] < target) {
        start = mid + 1;
      }
      else {
        end = mid - 1;
      }
    }

    printf("%d ", found);
  }
}
