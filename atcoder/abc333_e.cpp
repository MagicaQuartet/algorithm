#include<cstdio>
#include<cstring>
#include<utility>
#include<vector>
using namespace std;
#define pi pair<int, int>
#define vpi vector<pi >
#define vi vector<int>
#define vvi vector<vi >
int N;
int picked[200010];
int main() {
  scanf("%d", &N);
  memset(picked, 0, sizeof(picked));
  vpi actions;
  vvi potions = vvi(N+1, vi());
  for (int i=1; i<=N; i++) {
    int t, x;
    scanf("%d%d", &t, &x);
    actions.push_back({t, x});
    if (t == 1) {
      potions[x].push_back(i);
    }
  }

  for (int i=N; i>0; i--) {
    pi action = actions[i-1];
    if (action.first == 1) {
      continue;
    }
    int monster = action.second;

    if (potions[monster].size() == 0) {
      printf("-1\n");
      return 0;
    }
    
    bool found = false;
    for (vi::reverse_iterator rit = potions[monster].rbegin(); rit != potions[monster].rend(); ++rit) {
      if (*rit > i) {
        continue;
      }
      picked[*rit] = 1;
      potions[monster].erase(--rit.base());
      found = true;
      break;
    }

    if (!found) {
      printf("-1\n");
      return 0;
    }
  }

  int acc = 0;
  int maxAcc = 0;
  for (int i=1; i<=N; i++) {
    pi action = actions[i-1];
    if (action.first == 2) {
      acc--;
    }
    else if (picked[i] == 1) {
      acc++;
      if (maxAcc < acc) {
        maxAcc = acc;
      }
    }
  }
  printf("%d\n", maxAcc);

  for (int i=1; i<=N; i++) {
    pi action = actions[i-1];
    if (action.first == 2) {
      continue;
    }
    printf("%d ", picked[i]);
  }
  printf("\n");
}
