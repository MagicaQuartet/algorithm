#include<iostream>
#include<string>
#include<map>
using namespace std;
int N, M;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  map<string, string> pwdMap;
  while (N--) {
    string site, pwd;
    cin >> site >> pwd;
    pwdMap[site] = pwd;
  }
  while (M--) {
    string site;
    cin >> site;
    cout << pwdMap[site] << "\n";
  }
}
