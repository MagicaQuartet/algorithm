#include<iostream>
#include<vector>

using namespace std;

int main() {
  int N, step;
  cin >> N;
  
  vector<int> square;
  vector<int> dp;
  
  for (int i=1; i*i<=N; i++) {
    square.push_back(i*i);
  }
  
  for (int i=1; i<=N; i++) {
    int val = 100000;
    
    for (vector<int>::iterator it=square.begin(); it!=square.end(); ++it) {
      if ((*it)==i) {
        val = 1;
        break;
      }
      else if ((*it)<i) {
        if (val > dp[i-(*it)-1] + 1)
          val = dp[i-(*it)-1] + 1;
      }
      else
        break;
    }
    
    dp.push_back(val);
  }
  
  cout << dp[N-1] << endl;
  
  return 0;
}

/* 어떤 숫자 N에 대해 Dynamic programming을 이용하여 DP[N-제곱수]+1 (또는 N이 제곱수일 경우 1) 중 최솟값을 찾는다. */