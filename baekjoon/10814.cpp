#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int N;

bool cmp(pair<pair<int, int>, string>& member1, pair<pair<int, int>, string> member2) {
  if (member1.first.first != member2.first.first) {
    return member1.first.first < member2.first.first;
  }
  else {
    return member1.first.second < member2.first.second;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  vector<pair<pair<int, int>, string> > members;
  members.reserve(N);

  for (int i=0; i<N; i++) {
    int age;
    string name;

    cin >> age >> name;
    members.push_back({{age, i}, name});
  }

  sort(members.begin(), members.end());

  for (int i=0; i<N; i++) {
    cout << members[i].first.first << " " << members[i].second << "\n";
  }
}