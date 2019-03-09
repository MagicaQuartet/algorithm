#include<iostream>
#include<vector>

using namespace std;

int main() {
  int N, K, coin, answer;
  cin >> N >> K;
  
  vector<long> coins;
  
  for (int i=0;i<N;i++) {
    cin >> coin;
    coins.push_back(coin);
  }
  
  answer = 0;
  
  for (vector<long>::reverse_iterator it=coins.rbegin(); it!=coins.rend(); ++it) {
    if (*it <= K) {
      int temp = K/(*it);
      answer += temp;
      K -= temp*(*it);
    }
    
    if (K <= 0)
      break;
  }
  
  cout << answer << endl;
  
  return 0;
}