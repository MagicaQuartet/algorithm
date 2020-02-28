#include<iostream>
#include<string>
using namespace std;
int N, M, A[50], T[50], G[50], C[50];
string dna;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N >> M;
  
  for (int i=0; i<M; i++) {
    A[i] = T[i] = G[i] = C[i] = 0;
  }
  
  for (int i=0; i<N; i++) {
    cin >> dna;
    for (int i=0; i<M; i++) {
      if (dna[i] == 'A') A[i]++;
      else if (dna[i] == 'T') T[i]++;
      else if (dna[i] == 'G') G[i]++;
      else if (dna[i] == 'C') C[i]++;
    }
  }
  
  char c;
  int maxVal, sum = 0;
  for (int i=0; i<M; i++) {
    maxVal = 0;
    if (maxVal <= T[i]) {
      maxVal = T[i];
      c = 'T';
    }
    if (maxVal <= G[i]) {
      maxVal = G[i];
      c = 'G';
    }
    if (maxVal <= C[i]) {
      maxVal = C[i];
      c = 'C';
    }
    if (maxVal <= A[i]) {
      maxVal = A[i];
      c = 'A';
    }
    cout << c;
    sum += maxVal;
  }
  cout << '\n' << N*M-sum;
}
