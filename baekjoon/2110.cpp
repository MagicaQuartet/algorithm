#include<cstdio>
#include<algorithm>
using namespace std;
int N, C;
int house[200010];

int main() {
  scanf("%d %d", &N, &C);
  for (int i=1; i<=N; i++) {
    scanf("%d", house+i);
  }
  sort(house+1, house+N+1);

  int ansHead = 1;
  int ansTail = house[N] - house[1];
  int ans;
  while(ansHead <= ansTail) {
    ans = (ansHead + ansTail) / 2;

    int pos = 1;
    int cnt = 1;
    while (pos < N) {
      int head = pos;
      int tail = N;
      while (head <= tail) {
        if (head == tail) {
          if (house[head] - house[pos] == ans) {
            pos = head;
            cnt++;
          }
          else if (house[head] - house[pos] < ans) {
            if (head != N && house[head+1] - house[pos] >= ans) {
              pos = head + 1;
              cnt++;
            }
            else {
              pos = N;
            }
          }
          else {
            if (head != 1 && house[head-1] - house[pos] >= ans) {
              pos = head - 1;
            }
            else {
              pos = head;
            }
            cnt++;
          }
          break;
        }
        
        int mid = (head + tail) / 2;
        if (house[mid] - house[pos] == ans) {
          pos = mid;
          cnt++;
          break;
        }
        else if (house[mid] - house[pos] < ans) {
          head = mid + 1;
        }
        else {
          tail = max(head, mid - 1);
        }
      }
    }

    if (cnt >= C) {
      ansHead = ans + 1;
    }
    else {
      if (ansHead == ansTail) {
        ans--;
        break;
      }
      ansTail = ans - 1;
    }
  }

  printf("%d\n", ans);
}