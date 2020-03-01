#include<iostream>
#include<string>
using namespace std;
int N, idx1, idx2;
string channel;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  idx1 = idx2 = -1;
  
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> channel;
    if (channel == "KBS1") idx1 = i;
    else if (channel == "KBS2") idx2 = i;
    
    if (idx1 != -1 && idx2 != -1) break;
  }
  
  for (int i=0; i<idx1; i++) cout << '1';
  for (int i=idx1; i>0; i--) cout << '4';
  for (int i=0; i<idx2+(idx1>idx2 ? 1 : 0); i++) cout << '1';
  for (int i=idx2+(idx1>idx2 ? 1 : 0); i>1; i--) cout << '4';
}

/*
  꼭 최적해가 아니어도 된다. KBS1 집어오고 KBS2 집어오는 방법을 써도 조작 횟수가 500을 넘지 않는다.
*/