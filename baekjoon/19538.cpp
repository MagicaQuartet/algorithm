#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int N, M;

int main() {
  scanf("%d", &N);
  vector<vector<int> > adj;
  vector<int> adjNum(N, 0);
  vector<int> rumorAdjNum(N, 0);
  vector<int> rumorTime(N, -1);
  queue<pair<int, int> > q;

  for (int i=0; i<N; i++) {
    adj.push_back(vector<int>());

    int num;
    while(1) {
      scanf("%d", &num);
      if (!num) break;

      adj[i].push_back(num);
      adjNum[i]++;
    }
  }

  scanf("%d", &M);
  for (int i=0; i<M; i++) {
    int num;
    scanf("%d", &num);
    q.push(make_pair(num, 0));
  }

  while(!q.empty()) {
    int person = q.front().first;
    int cnt = q.front().second;
    q.pop();
    
    if (cnt != 0 && rumorTime[person-1] > -1) {
      continue;
    }

    rumorTime[person-1] = cnt;

    for (int i=0; i<adj[person-1].size(); i++) {
      int adjPerson = adj[person-1][i];
      rumorAdjNum[adjPerson-1]++;
      if (rumorAdjNum[adjPerson-1] >= (adjNum[adjPerson-1]+1)/2) {
        q.push(make_pair(adjPerson, cnt+1));
      }
    }
  }

  for (int i=0; i<N; i++) {
    printf("%d ", rumorTime[i]);
  }
  printf("\n");
}
