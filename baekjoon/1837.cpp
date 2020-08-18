#include<iostream>
#include<string>
#include<vector>
using namespace std;

string P;
int K;
vector<int> primes;

void calculatePrimes() {
  primes.reserve(K/2);
  primes.push_back(2);
  for (int i=3; i<K; i+=2) {
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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> P >> K;
  calculatePrimes();

  int step;
  for (auto prime: primes) {
    if (prime >= K) {
      break;
    }

    step = 0;
    for (auto cdigit: P) {
      int digit = cdigit-'0';
      step = (step*10 + digit)%prime;
    }
    if (step == 0) {
      cout << "BAD " << prime << "\n";
      return 0;
    }
  }
  cout << "GOOD\n";
}