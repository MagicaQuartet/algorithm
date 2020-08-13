#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> primes;

void getPrimes() {
  for (int i=3; i<= 1000000; i+=2) {
    int isPrime = 1;

    for (int j=2; j*j <= i; j++) {
      if (i%j == 0) {
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
  getPrimes();
  while(1) {
    scanf("%d", &n);
    if (!n) { break; }
    
    int found = 0;
    for (auto p: primes) {
      vector<int>::iterator lb = lower_bound(primes.begin(), primes.end(), n-p);
      if (p + *lb == n) {
        found = 1;
        printf("%d = %d + %d\n", n, p, *lb);
        break;
      }
    }

    if (!found) {
      printf("Goldbach's conjecture is wrong\n");
    }
  }
}