#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int N;
vector<ll> primes;

void getPrimes() {
  primes.reserve(N+1);
  primes.push_back(0);
  for (int i=2; i<= N; i++) {
    int isPrime = 1;

    for (int j=2; j*j <= i; j++) {
      if (i%j == 0) {
        isPrime = 0;
        break;
      }
    }

    if (isPrime) {
      primes.push_back(primes.back()+i);
    }
  }
}

int main() {
  scanf("%d", &N);
  getPrimes();
  int cnt = 0;
  int lhs = 0, rhs = 1;

  while (rhs < primes.size()) {
    ll sum = primes[rhs] - primes[lhs];
    if (N == sum) {
      cnt++;
    }

    if (lhs == rhs-1) {
      rhs++;
    }
    else if (N >= sum) {
      rhs++;
    }
    else {
      lhs++;
    }
  }
  printf("%d\n", cnt);
}