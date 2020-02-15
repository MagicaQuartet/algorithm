#include<cstdio>
#include<vector>
using namespace std;
int N, num, cnt;
bool isPrime;
vector<int> prime;
int main() {
  scanf("%d", &N);
  for (int i=2; i<=1000; i++) {
    isPrime = true;
    for (auto x : prime) {
      if (x*x >= i) break;
      if (i%x == 0) {
        isPrime = false;
        break;
      }
    }
    
    if (isPrime) {
      prime.push_back(i);
    }
  }
  
  cnt=0;
  for (int i=0; i<N; i++) {
    scanf("%d", &num);
    if (num == 1) continue;
    
    isPrime = true;
    for (auto x : prime) {
      if (x*x > num) break;
      if (num%x == 0) {
        isPrime = false;
        break;
      }
    }
    
    if (isPrime) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}