#include<cstdio>
#include<queue>
#include<functional>
#define ll long long
using namespace std;

int n, m;
ll sum;

int main() {
  scanf("%d %d", &n, &m);
  priority_queue<ll, vector<ll>, greater<ll> > pq;

  for (int i=0; i<n; i++) {
    int num;
    scanf("%d", &num);
    pq.push(num);
  }

  for (int i=0; i<m; i++) {
    ll a = pq.top();
    pq.pop();
    ll b = pq.top();
    pq.pop();

    pq.push(a+b);
    pq.push(a+b);
  }

  sum = 0;
  for (int i=0; i<n; i++) {
    sum += pq.top();
    pq.pop();
  }

  printf("%lld\n", sum);
}

/*
  값의 범위를 잘 체크하자..
*/