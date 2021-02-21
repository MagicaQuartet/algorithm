#include<cstdio>
#include<list>
using namespace std;
#define MAX 1000000000000000000
#define ll long long
#define lll list<ll>
int N;
lll arr[10010];
lll fibo(int n) {
  if (arr[n].size() > 0) {
    return arr[n];
  }
  lll ret1 = fibo(n-2);
  lll ret2 = fibo(n-1);
  int carry = 0;
  lll::iterator it1 = ret1.begin();
  lll::iterator it2 = ret2.begin();
  while (it1 != ret1.end()) {
    if (*it1+*it2+carry >= MAX || *it1+*it2+carry <= 0) {
      arr[n].push_back((*it1-MAX)+*it2+carry);
      carry = 1;
    }
    else {
      arr[n].push_back(*it1+*it2+carry);
      carry = 0;
    }
    ++it1;
    ++it2;
  }
  while (it2 != ret2.end()) {
    if (*it2+carry >= MAX || *it2+carry <= 0) {
      arr[n].push_back((*it2-MAX)+carry);
      carry = 1;
    }
    else {
      arr[n].push_back(*it2+carry);
      carry = 0;
    }
    ++it2;
  }
  if (carry) {
    arr[n].push_back(carry);
  }
  return arr[n];
}
int main() {
  scanf("%d", &N);
  for (int i=0; i<=N; i++) {
    arr[i] = lll();
  }
  arr[0].push_back(0);
  arr[1].push_back(1);
  lll ret = fibo(N);
  for (lll::reverse_iterator it=ret.rbegin(); it != ret.rend(); ++it) {
    if (it == ret.rbegin()) {
      printf("%lld", *it);
    }
    else {
      printf("%018lld", *it);
    }
  }
  printf("\n");
}