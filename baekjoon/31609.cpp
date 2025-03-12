#include<cstdio>
#include<set>
using namespace std;

int n;
set<int> s;
int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    int num;
    scanf("%d", &num);
    s.insert(num);
  }
  for (set<int>::iterator it=s.begin(); it!=s.end(); ++it) {
    printf("%d\n", *it);
  }
}
