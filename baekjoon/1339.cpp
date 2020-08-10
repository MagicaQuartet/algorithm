#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N;
int w[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int nums[26];
int weight[26];
string s;

bool cmp(int lhs, int rhs) {
  return weight[lhs] > weight[rhs];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(weight, 0, sizeof(weight));
  for (int i=0; i<26; i++) { nums[i] = i; }

  cin >> N;

  for (int n=0; n<N; n++) {
    cin >> s;
    for (int i=0; i<s.size(); i++) {
      weight[s[i]-'A'] += w[s.size()-1-i];
    }
  }

  sort(nums, nums+26, cmp);
  int sum = 0;
  int step = 9;
  for (int i=0; i<26; i++) {
    if (weight[nums[i]] == 0) { break; }

    sum += step*weight[nums[i]];
    step--;
  }

  cout << sum << endl;
}