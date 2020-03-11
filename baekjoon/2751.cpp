#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int main() {
  scanf("%d", &N);
  vector<int> data;
  data.reserve(N);
  while(N--) {
    int num;
    scanf("%d", &num);
    data.push_back(num);
  }
  
  sort(data.begin(), data.end());
  for (auto i : data) {
    printf("%d\n", i);
  }
}