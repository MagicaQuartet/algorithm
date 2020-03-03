#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int N, grade;
long long ans;
int main() {
  scanf("%d", &N);
  vector<int> data(N, 0);
  for (int i=0; i<N; i++) {
    scanf("%d", &data[i]);
  }
  
  sort(data.begin(), data.end());
  
  grade = 1;
  for (int i=0; i<N; i++) {
    ans += (data[i]-grade > 0 ? data[i]-grade : grade-data[i]);
    grade++;
  }
  
  printf("%lld\n", ans);
}