#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int L, C;

int checkMoeum(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return 1;
  else
    return 0;
}

void makeCrypto(vector<char> &data, vector<char> &selected, int mo, int idx) {
  if (idx == C) {
    if (selected.size() == L && mo >= 1 && L-mo >= 2) {
      for (auto c : selected) {
        printf("%c", c);
      }
      printf("\n");
    }
    
    return;
  }
  
  selected.push_back(data[idx]);
  makeCrypto(data, selected, mo+checkMoeum(data[idx]), idx+1);
  selected.pop_back();
  makeCrypto(data, selected, mo, idx+1);
  return;
}

int main() {
  char c;
  vector<char> data;
  
  scanf("%d %d", &L, &C);
  data.reserve(C);
  for (int i=0; i<C; i++) {
    do {
      scanf("%c", &c);
    } while (c == '\n' || c == ' ');
    data.push_back(c);
  }
  sort(data.begin(), data.end());
  
  vector<char> v;
  makeCrypto(data, v, 0, 0);
  return 0;
}