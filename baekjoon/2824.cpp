#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 1000000000
#define ll long long
using namespace std;

int N, M, overflow;
ll ans;
vector<int> primes;

void calculatePrimes() {
  primes.push_back(2);
  for (int i=3; i*i<=INF; i+=2) {
    int isPrime = 1;
    for (auto p: primes) {
      if (i%p==0) {
        isPrime = 0;
        break;
      }
    }

    if (isPrime) {
      primes.push_back(i);
    }
  }
}

int main() {
  calculatePrimes();
  vector<int> cntA(primes.size(), 0);
  vector<int> cntB(primes.size(), 0);
  ans = 1;
  overflow = 0;

  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    for (int idx=0; idx<primes.size(); idx++) {
      while(num > 1) {
        if (num%primes[idx] > 0) {
          break;
        }
        cntA[idx]++;
        num /= primes[idx];
      }
    }

    if (num > 1) {
      ans = ans*num;
      if (ans >= INF) {
        overflow = 1;
        ans %= INF;
      }
    }
  }

  scanf("%d", &M);
  for (int i=0; i<M; i++) {
    int num;
    scanf("%d", &num);
    for (int idx=0; idx<primes.size(); idx++) {
      while(num > 1) {
        if (num%primes[idx] > 0) {
          break;
        }
        cntB[idx]++;
        num /= primes[idx];
      }
    }

    if (num > 1) {
      ans = ans*num;
      if (ans >= INF) {
        overflow = 1;
        ans %= INF;
      }
    }
  }

  for (int i=0; i<primes.size(); i++) {
    int cnt = min(cntA[i], cntB[i]);
    for (int j=1; j<=cnt; j++) {
      ans = ans*primes[i];
      if (ans >= INF) {
        overflow = 1;
        ans %= INF;
      }
    }
  }

  printf(overflow ? "%09lld\n" : "%lld\n", ans);
}