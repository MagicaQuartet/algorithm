#include<cstdio>
#include<vector>
#define ll long long 
using namespace std;
ll a, b;
int cnt, NN[1000001];
int main() {
  scanf("%lld %lld", &a, &b);
  for (ll i=a; i<=b; i++) {
    NN[i-a] = 1;
  }
  cnt = b-a+1;
  for (ll i=2; i*i<=b; i++) {
    for (long long j=(a-1)/(i*i)+1; j*(i*i) <= b; j++) {
      if (NN[j*(i*i)-a] == 1) {
        cnt--;
        NN[j*(i*i)-a] = 0;
      }
    }
  }
  
  printf("%d\n", cnt);
}

/* 1보다 크고 b의 제곱근보다 작거나 같은 제곱수를 미리 구한 다음, 에라토스테네스의 체를 만들어서 체크를 했다. 그런데 이렇게 푸는게 아닌가??? */

/* (추가) 아 제곱수를 미리 구할 필요는 없구나... 그나마 좀 볼만해졌네 */