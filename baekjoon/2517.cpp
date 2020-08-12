#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int runners[500010], temp[500010];
int counts[500010], tempCounts[500010];
int originIdx[500010], tempIdx[500010];

bool srt(int lhs, int rhs) {
  return originIdx[lhs] < originIdx[rhs];
}

void merge(int left, int mid, int right) {
  int p1 = left;
  int p2 = mid + 1;
  int idx = left;
  int cnt = 0;

  while (p1 <= mid && p2 <= right) {
    if (runners[p1] < runners[p2]) {
      cnt++;
      temp[idx] = runners[p1];
      tempCounts[idx] = counts[p1];
      tempIdx[idx] = originIdx[p1];
      p1++;
    }
    else {
      temp[idx] = runners[p2];
      tempCounts[idx] = counts[p2] + cnt;
      tempIdx[idx] = originIdx[p2];
      p2++;
    }
    idx++;
  }

  while (p1 <= mid) {
    temp[idx] = runners[p1];
    tempCounts[idx] = counts[p1];
    tempIdx[idx] = originIdx[p1];
    idx++;
    p1++;
  }

  while (p2 <= right) {
    temp[idx] = runners[p2];
    tempCounts[idx] = counts[p2] + cnt;
    tempIdx[idx] = originIdx[p2];
    idx++;
    p2++;
  }

  for (int i=left; i<=right; i++) {
    runners[i] = temp[i];
    counts[i] = tempCounts[i];
    originIdx[i] = tempIdx[i];
  }
}

void mergeSort(int left, int right) {
  if (left < right) {
    int mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);
    merge(left, mid, right);
  }
}

int main() {
  scanf("%d", &N);

  for (int i=0; i<N; i++) {
    scanf("%d", runners+i);
    counts[i] = 0;
    originIdx[i] = i;
  }

  mergeSort(0, N-1);
  for (int i=0; i<N; i++) {
    tempIdx[i] = i;
  }
  sort(tempIdx, tempIdx+N, srt);
  for (int i=0; i<N; i++) {
    printf("%d\n", i+1-counts[tempIdx[i]]);
  }
}

/*
  inversion count를 처음 배워서 구현해봤는데, 너무 배열을 많이 쓴거 아닌가??
  덜 쓸 수 있으면 더 좋을텐데... 공부해봐야겠다.
*/