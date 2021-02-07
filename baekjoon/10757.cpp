#include<iostream>
#include<string>
using namespace std;
string A, B, ans;
int carry;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B;
  carry = 0;
  ans = "";
  for (int i=0; ; i++) {
    int aidx = A.size() - 1 - i;
    int bidx = B.size() - 1 - i;
    if (aidx < 0 && bidx < 0) {
      if (carry) ans = (char)('0' + carry) + ans;
      break;
    }

    int a = (aidx < 0) ? 0 : A[aidx] - '0';
    int b = (bidx < 0) ? 0 : B[bidx] - '0';
    int sum = a + b + carry;
    carry = sum / 10;
    ans = (char)('0' + sum%10) + ans;
  }
  cout << ans << "\n";
}