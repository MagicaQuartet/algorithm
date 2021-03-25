#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int N, M;
int strToNum(string str) {
  int ret = 0;
  for (int i=0; i<str.size(); i++) {
    ret *= 10;
    ret += str[i]-'0';
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<string> pokemonList;
  map<string, int> pokemonMap;
  cin >> N >> M;
  for (int i=0; i<N; i++) {
    string pokemon;
    cin >> pokemon;
    pokemonList.push_back(pokemon);
    pokemonMap[pokemon] = i;
  }
  for (int i=0; i<M; i++) {
    string query;
    cin >> query;
    if (query[0] >= '0' && query[0] <= '9') {
      cout << pokemonList[strToNum(query)-1] << "\n";
    }
    else {
      cout << pokemonMap[query]+1 << "\n";
    }
  }
}
