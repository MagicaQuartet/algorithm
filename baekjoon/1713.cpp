#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 987654321

int N, M;
int pic[22];
int timestamp[22];
int voteCnt[22];

int main() {
  scanf("%d %d", &N, &M);
  memset(pic, -1, sizeof(pic));
  memset(timestamp, -1, sizeof(timestamp));
  memset(voteCnt, -1, sizeof(voteCnt));

  for (int i=0; i<M; i++) {
    int vote;
    int minT = INF, minV = INF, minIdx;
    scanf("%d", &vote);
    
    for (int j=0; j<N; j++) {
      if (pic[j] == -1) {
        pic[j] = vote;
        timestamp[j] = i;
        voteCnt[j] = 1;
        minIdx = -1;
        break;
      }
      else if (pic[j] == vote) {
        voteCnt[j]++;
        minIdx = -1;
        break;
      }

      if (minV > voteCnt[j] || (minV == voteCnt[j] && minT > timestamp[j])) {
        minT = timestamp[j];
        minV = voteCnt[j];
        minIdx = j;
      }
    }

    if (minIdx > -1) {
      pic[minIdx] = vote;
      timestamp[minIdx] = i;
      voteCnt[minIdx] = 1;
    }
  }

  sort(pic, pic+N);

  for (int i=0; i<N; i++) {
    if (pic[i] == -1) { continue; }
    printf("%d ", pic[i]);
  }
  printf("\n");
}