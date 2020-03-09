#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, cnt, dp[10000];
int main() {
  scanf("%d %d", &N, &M);
  vector<int> bookP;
  vector<int> bookN;
  bookP.reserve(N);
  bookN.reserve(N);
  for (int i=0; i<N; i++) {
    int book;
    scanf("%d", &book);
    if (book > 0) bookP.push_back(book);
    else bookN.push_back(-book);
  }
  
  sort(bookP.begin(), bookP.end());
  sort(bookN.begin(), bookN.end());
  
  memset(dp, 0, 4*M);
  for (int i=0; i<bookP.size(); i++) {
    int minVal = 987654321;
    for (int j=0; j<M; j++) {
      if (dp[j] < minVal) {
        minVal = dp[j];
      }
    }
    dp[i%M] = 2*bookP[i] + minVal;
  }
  cnt += dp[(bookP.size()-1)%M];
  
  memset(dp, 0, 4*M);
  for (int i=0; i<bookN.size(); i++) {
    int minVal = 987654321;
    for (int j=0; j<M; j++) {
      if (dp[j] < minVal) {
        minVal = dp[j];
      }
    }
    dp[i%M] = 2*bookN[i] + minVal;
  }
  cnt += dp[(bookN.size()-1)%M];
  
  if (bookP.empty()) {
    cnt -= bookN.back();
  }
  else if (bookN.empty()){
    cnt -= bookP.back();
  }
  else {
    cnt -= (bookP.back() < bookN.back() ? bookN.back() : bookP.back()); 
  }
  
  printf("%d\n", cnt);
}

/*
  위치가 음수인 책과 양수인 책으로 나누고 각 배열에서 어떻게 묶음을 지어야 최적일지를 dp로 찾도록 했는데 일단 통과는 했으나 아무래도 더 간단한 해법이 있는 모양이다.
*/