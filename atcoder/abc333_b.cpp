#include<iostream>
#include<string>
using namespace std;
string S, T;
int main() {
  cin >> S >> T;
  int diff1 = S[0]-S[1];
  if (diff1 < 0) diff1 = -diff1;
  if (diff1 == 3) diff1 = 2;
  if (diff1 == 4) diff1 = 1;
  int diff2 = T[0]-T[1];
  if (diff2 < 0) diff2 = -diff2;
  if (diff2 == 3) diff2 = 2;
  if (diff2 == 4) diff2 = 1;
  cout << (diff1 == diff2 ? "Yes" : "No");
}
