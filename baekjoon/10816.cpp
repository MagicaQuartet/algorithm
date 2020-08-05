#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;

int main() {
  scanf("%d", &N);
  vector<int> cards(N, 0);

  for (int i=0; i<N; i++) {
    int card;
    scanf("%d", &card);
    cards[i] = card;
  }

  sort(cards.begin(), cards.end());

  scanf("%d", &M);
  for (int i=0; i<M; i++) {
    int query, cnt;
    scanf("%d", &query);

    vector<int>::iterator lb = lower_bound(cards.begin(), cards.end(), query);
    vector<int>::iterator ub = upper_bound(cards.begin(), cards.end(), query);
    
    printf("%d ", ub-lb);
  }
  printf("\n");
}

/*
  같은 컨테이너의 이터레이터끼리 빼면 위치 차이값이 나오는구나! 처음 알았네..
*/