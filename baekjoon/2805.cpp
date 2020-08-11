#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

int N;
ll M;
int tree[1000010];

bool cmp(int lhs, int rhs) {
  return lhs > rhs;
}

int main() {
  scanf("%d %lld", &N, &M);
  for (int i=0; i<N; i++) {
    scanf("%d", tree+i);
  }

  sort(tree, tree+N, cmp);

  int sum = 0;
  int height = tree[0];
  for (ll i=0; i<N-1; i++) {
    if (sum + (i+1)*(tree[i]-tree[i+1]) < M) {
      sum += (i+1)*(tree[i]-tree[i+1]);
      height = tree[i+1];
    }
    else {
      printf("%lld\n", height - ((M-sum-1)/(i+1) + 1));
      return 0;
    }
  }

  printf("%lld\n", height - ((M-sum-1)/N + 1));
}