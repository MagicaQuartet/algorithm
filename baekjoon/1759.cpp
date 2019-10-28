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

int makeCrypto(vector<char> &all, vector<char> &selected, int ja, int mo, int idx) {
  
}

int main() {
  char c;
  vector<char> all;
  
  scanf("%d %d", &L, &C);
  for (int i=0; i<C; i++) {
    scanf("%c", &c);
    all.push_back(c);
  }
  
  makeCrypto(all, vector<char>(), 0, 0, 0);
  return 0;
}