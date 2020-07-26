#include<cstdio>
#include<vector>
#define ll long long
using namespace std;

int N, u, v;
ll D, G;

int main() {
  scanf("%d", &N);
  vector<vector<int> > tree(N, vector<int>());
  vector<int> childCnt(N, 0);
  D = G = 0;

  for (int i=0; i<N-1; i++) {
    scanf("%d %d", &u, &v);

    tree[u-1].push_back(v-1);   // 혹시 모르니까 1씩 줄여서 저장
    tree[v-1].push_back(u-1);
  }

  for (int i=0; i<N; i++) {
    childCnt[i] = tree[i].size();
  }

  for (int i=0; i<N; i++) {
    ll cnt = childCnt[i];
    G += cnt*(cnt-1)*(cnt-2)/6;

    if (cnt == 1) continue;

    for (int j=0; j<tree[i].size(); j++) {
      int child = tree[i][j];  

      if (i < child && childCnt[child] >= 2) {
        D += (cnt-1)*(childCnt[child] - 1);
      }
    }
  }

  printf("%s\n", D == 3*G ? "DUDUDUNGA" : (D > 3*G ? "D" : "G"));
}