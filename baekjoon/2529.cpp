#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int k, indegree1[10], indegree2[10];
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> k;
  cin.ignore();
  getline(cin, s);
  memset(indegree1, 0, sizeof(indegree1));
  memset(indegree2, 0, sizeof(indegree2));
  for (int i=0; i<k; i++) {
    if (s[2*i] == '<') {
      indegree1[i]++;
      indegree2[i+1]++;
    }
    else {
      indegree1[i+1]++;
      indegree2[i]++;
    }
  }
  int step1 = 9;
  int step2 = 0;
  priority_queue<int, vector<int>, greater<int> > pq1, pq2;
  for (int i=0; i<=k; i++) {
    if (indegree1[i] == 0) pq1.push(i);
    if (indegree2[i] == 0) pq2.push(i);
  }

  string ans1(k+1, '0');
  string ans2(k+1, '0');
  while(!pq1.empty()) {
    int idx = pq1.top();
    pq1.pop();
    ans1[idx] = '0' + (step1--);
    if (idx != k && s[2*idx] == '>') {
      indegree1[idx+1]--;
      if (indegree1[idx+1] == 0) pq1.push(idx+1);
    }
    if (idx != 0 && s[2*(idx-1)] == '<') {
      indegree1[idx-1]--;
      if (indegree1[idx-1] == 0) pq1.push(idx-1);
    }
  }
  while(!pq2.empty()) {
    int idx = pq2.top();
    pq2.pop();
    ans2[idx] = '0' + (step2++);
    if (idx != 0 && s[2*(idx-1)] == '>') {
      indegree2[idx-1]--;
      if (indegree2[idx-1] == 0) pq2.push(idx-1);
    }
    if (idx != k && s[2*idx] == '<') {
      indegree2[idx+1]--;
      if (indegree2[idx+1] == 0) pq2.push(idx+1);
    }
  }
  cout << ans1 << "\n" << ans2 << "\n";
}