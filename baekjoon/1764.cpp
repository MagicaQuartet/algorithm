#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;

  vector<string> arr;
  vector<string> ans;

  for (int i=0; i<N; i++) {
    string person;
    cin >> person;
    arr.push_back(person);
  }
  sort(arr.begin(), arr.end());

  for (int i=0; i<M; i++) {
    string person;
    cin >> person;

    int start = 0;
    int end = N-1;
    int mid;
    while(start <= end) {
      mid = (start + end) / 2;
      if (!person.compare(arr[mid])) {
        ans.push_back(person);
        break;
      }
      if (start == end) {
        break;
      }

      if (person < arr[mid]) {
        end = mid - 1;
      }
      else {
        start = mid + 1;
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (auto p: ans) {
    cout << p << "\n";
  }
}

// 트라이 등 스트링 자료구조를 쓰면 좀 낫겠지만
