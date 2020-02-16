#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string N;
int sum;
int main() {
  cin.sync_with_stdio(false);
  cin >> N;
  sort(N.rbegin(), N.rend());
  
  if (N.back() == '0') {
    sum = 0;
    for (auto i : N) {
      sum += i-'0';
    }

    cout << (sum%3 ? "-1" : N) << endl;
  }
  else {
    cout << -1 << endl;
  }
}

/*
  N을 다 받고 자리수를 내림차순 정렬한 다음 답을 구하는 아주 간단한 방법으로 풀었는데
  다른 풀이를 보니 자리수를 하나하나 받으면서 각 자리수가 등장한 횟수와 자리수의 총합을 구하는 등 더 깔끔하고 효율적인 풀이가 있었다.
*/