#include<iostream>
#include<string>
using namespace std;
string N;
int carry;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  string shifted = N + "0000";
  int carry = 0;
  for (int i=0; i<N.size(); i++) {
    int sidx = shifted.size()-1-i;
    int idx = N.size()-1-i;
    int snum = shifted[sidx]-'0';
    int num = N[idx]-'0';
    int sum = num + snum + carry;
    shifted[sidx] = (sum%2) + '0';
    carry = sum/2;
  }
  for (int i=N.size(); i<shifted.size(); i++) {
    int sidx = shifted.size()-1-i;
    int snum = shifted[sidx]-'0';
    int sum = snum + carry;
    shifted[sidx] = (sum%2) + '0';
    carry = sum/2;
  }
  if (carry) {
    shifted = "1" + shifted;
  }
  cout << shifted << "\n";
}