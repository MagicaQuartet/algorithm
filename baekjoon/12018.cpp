#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, cnt;
bool cmp(int a, int b) {return a>b;}
int main() {
  scanf("%d %d", &n, &m);
  vector<int> threshold(n, 0);
  for (int i=0; i<n; i++) {
    int p, l;
    scanf("%d %d", &p, &l);
    
    vector<int> data(p, 0);
    for (int j=0; j<p; j++) {
      scanf("%d", &data[j]);
    }
    
    if (p < l) {
      threshold[i] = 1;
    }
    else {
      sort(data.begin(), data.end(), cmp);
      threshold[i] = data[l-1];
    }
  }
  
  sort(threshold.begin(), threshold.end());
  cnt = 0;
  for (int i=0; i<n; i++) {
    if (m - threshold[i] < 0) {
      break;
    }
    cnt++;
    m -= threshold[i];
  }
  printf("%d\n", cnt);
}

/*
  적은 마일리지로 수강할 수 있는 과목부터 집자
*/