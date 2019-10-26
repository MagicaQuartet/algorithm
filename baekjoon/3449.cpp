#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    string a, b;
    int d = 0;
    cin >> a >> b;
    for (int i=0; i<a.size(); i++) {
      if (a[i] != b[i])
        d++;
    }
    printf("Hamming distance is %d.\n", d);
  }
  return 0;
}