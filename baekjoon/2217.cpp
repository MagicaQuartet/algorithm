#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, rope, ans;
vector<int> data;
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &rope);
    data.push_back(rope);
  }
  
  sort(data.begin(), data.end());
  ans = data[0]*N;
  for (int i=1; i<N; i++) {
    ans = (ans < data[i]*(N-i)) ? data[i]*(N-i) : ans;
  }
  printf("%d\n", ans);
}

/*
  정렬 후 버틸 수 있는 중량이 작은 로프부터 시작해서 순차적으로 이전 로프를 빼는 것이 나은지 아닌지를 체크한다. 로프가 듬성듬성 제외되는 경우는 없다.
*/