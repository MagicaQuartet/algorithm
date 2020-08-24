#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int seq[1000010];
int parent[1000010];
int len;

bool cmp(int lhs, int rhs) {
  return seq[lhs] < seq[rhs];
}

void solve(int idx) {
  if (parent[idx] == -1) {
    printf("%d ", seq[idx]);
    return;
  }

  solve(parent[idx]);
  printf("%d ", seq[idx]);
}

int main() {
  len = 0;
  scanf("%d", &N);
  vector<int> lis;

  for (int i=0; i<N; i++) {
    scanf("%d", seq+i);
  }

  for (int i=0; i<N; i++) {
    vector<int>::iterator lb = lower_bound(lis.begin(), lis.end(), i, cmp);

    if (lb != lis.end()) {
      if (seq[i] == seq[*lb]) {
        continue;
      }

      *lb = i;
      parent[i] = (lb == lis.begin()) ? -1 : *(prev(lb));
    }
    else {
      parent[i] = lis.empty() ? -1 : *(prev(lb));
      lis.push_back(i);
      len++;
    }
  }

  printf("%d\n", len);
  solve(lis[len-1]);
  printf("\n");
}

/*
  LIS의 요소도 추적할 수 있도록
  lis, parent에 인덱스 값을 저장하도록 하였음
*/