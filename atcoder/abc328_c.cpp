#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int N, Q;
string S;
int sum1[300010], sum2[300010];
int main() {
  cin >> N >> Q >> S;
  memset(sum1, 0, sizeof(sum1));
  memset(sum2, 0, sizeof(sum2));
  for (int i=1; i<=N; i++) {
    sum1[i] = sum1[i-1];
    sum2[i] = sum2[i-1];
    if (i<N && S[i-1] == S[i]) {
      sum1[i]++;
    }
    if (i >= 1 && S[i-2] == S[i-1]) {
      sum2[i]++;
    }
  }
  for (int i=0; i<Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << sum2[r]-sum1[l-1] << "\n";
  }
}
