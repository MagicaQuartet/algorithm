#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define vi vector<int>
using namespace std;

string raw, s;
int A[200010];
vi segtree[800010];
int n, r, p, m, idx, len;

vi merge(vi& arr1, vi& arr2) {
  vi v;
  v.reserve(arr1.size() + arr2.size());
  int idx1 = 0;
  int idx2 = 0;
  while(idx1 < arr1.size() && idx2 < arr2.size()) {
    if(arr1[idx1] < arr2[idx2]) v.push_back(arr1[idx1++]);
    else v.push_back(arr2[idx2++]);
  }
  while(idx1 < arr1.size()) v.push_back(arr1[idx1++]);
  while(idx2 < arr2.size()) v.push_back(arr2[idx2++]);
  return v;
}

vi construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) return segtree[node] = vi(1, nodeLeft+A[nodeLeft]);
  int mid = (nodeLeft+nodeRight)/2;
  vi retLeft = construct(2*node, nodeLeft, mid);
  vi retRight = construct(2*node+1, mid+1, nodeRight);
  vi ret = merge(retLeft, retRight);
  return segtree[node] = ret;
}

int query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (nodeRight < left || right < nodeLeft) return 0;
  if (left <= nodeLeft && nodeRight <= right) {
    vi v = segtree[node];
    vi::iterator lb = lower_bound(v.begin(), v.end(), idx);
    return v.end() - lb;
  };
  int mid = (nodeLeft+nodeRight)/2;
  int retLeft = query(2*node, nodeLeft, mid, left, right);
  int retRight = query(2*node+1, mid+1, nodeRight, left, right);
  return retLeft + retRight;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> raw;
  s = "";
  for (int i=raw.size()-1; i>=0; i--) {
    s += '#';
    s += raw[i];
  }

  n = s.size();
  r = p = 0;
  for (int i=1; i<=n; i++) {
    A[i] = (i<=r) ? min(r-i, A[2*p-i]) : 0;
    while(i-A[i]-1 >= 0 && i+A[i]+1 < n && s[i-A[i]-1] == s[i+A[i]+1]) A[i]++;
    if (r < i+A[i]) {
      r = i+A[i];
      p = i;
    }
  }

  construct(1, 1, n);
  cin >> m;
  while(m--) {
    cin >> idx >> len;
    if (len > raw.size()) {
      cout << '0' << "\n";
      continue;
    }
    idx = 2*idx+1;
    int minP = idx + len - 1;
    idx = n-idx;
    minP = n-minP;
    int ret = query(1, 1, n, idx/2, minP);
    cout << ret << "\n";
  }
}

// Manacher + Segment Tree (BIT으로 구현하는게 더 좋을 듯 한데 기억이 안나서..)
