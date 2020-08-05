#include<cstdio>
#include<queue>
using namespace std;

int N;

int main() {
  scanf("%d", &N);
  queue<int> cards;

  for (int i=0; i<N; i++) {
    cards.push(i+1);
  }

  while(cards.size() > 1) {
    cards.pop();
    cards.push(cards.front());
    cards.pop();
  }

  printf("%d\n", cards.front());
}

/*
  이거 어떻게 N 넣자마자 바로 답 계산하는 수학적 풀이 없나..?
*/