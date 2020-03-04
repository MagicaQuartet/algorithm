#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, A, B, C, cal, cost;
bool cmp(int a, int b) {return a>b;}
int main() {
  scanf("%d %d %d %d", &N, &A, &B, &C);
  vector<int> data(N, 0);
  
  for (int i=0; i<N; i++) {
    scanf("%d", &data[i]);
  }
  
  sort(data.begin(), data.end(), cmp);
  cal = C;
  cost = A;
  for (auto i : data) {
    if (cal/cost <= (cal+i)/(cost+B)) {
      cal += i;
      cost += B;
    }
    else {
      break;
    }
  }
  
  printf("%d\n", cal/cost);
}

/*
  토핑 값은 다 같으니까 일단 열랑 높은 토핑부터 집어보면 된다
*/