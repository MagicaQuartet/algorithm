#include<iostream>
#include<string>
using namespace std;

string S;

bool isSymmetric(char c1, char c2) {
  if (c1 == 'A' && c2 == 'A') return true;
  if (c1 == 'H' && c2 == 'H') return true;
  if (c1 == 'I' && c2 == 'I') return true;
  if (c1 == 'M' && c2 == 'M') return true;
  if (c1 == 'O' && c2 == 'O') return true;
  if (c1 == 'T' && c2 == 'T') return true;
  if (c1 == 'U' && c2 == 'U') return true;
  if (c1 == 'V' && c2 == 'V') return true;
  if (c1 == 'W' && c2 == 'W') return true;
  if (c1 == 'X' && c2 == 'X') return true;
  if (c1 == 'Y' && c2 == 'Y') return true;
  if (c1 == 'i' && c2 == 'i') return true;
  if (c1 == 'l' && c2 == 'l') return true;
  if (c1 == 'm' && c2 == 'm') return true;
  if (c1 == 'n' && c2 == 'n') return true;
  if (c1 == 'o' && c2 == 'o') return true;
  if (c1 == 'u' && c2 == 'u') return true;
  if (c1 == 'v' && c2 == 'v') return true;
  if (c1 == 'w' && c2 == 'w') return true;
  if (c1 == 'x' && c2 == 'x') return true;
  if (c1 == '0' && c2 == '0') return true;
  if (c1 == '1' && c2 == '1') return true;
  if (c1 == '2' && c2 == '2') return true;
  if (c1 == '8' && c2 == '8') return true;
  if (c1 == 'E' && c2 == '3') return true;
  if (c1 == 'S' && c2 == '2') return true;
  if (c1 == 'Z' && c2 == '5') return true;
  if (c1 == 'b' && c2 == 'd') return true;
  if (c1 == 'd' && c2 == 'b') return true;
  if (c1 == 'p' && c2 == 'q') return true;
  if (c1 == 'q' && c2 == 'p') return true;
  if (c1 == 'r' && c2 == '7') return true;
  if (c1 == '2' && c2 == 'S') return true;
  if (c1 == '3' && c2 == 'E') return true;
  if (c1 == '5' && c2 == 'Z') return true;
  if (c1 == '7' && c2 == 'r') return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;
  int head = 0;
  int tail = S.size()-1;
  int possible = 1;
  while (head <= tail) {
    char c1 = S[head];
    char c2 = S[tail];
    if (isSymmetric(c1, c2)) {
      head++;
      tail--;
      continue;
    }
    if (c1 == 'a' && c2 == 'a' || c1 == 'a' && c2 == 'A' || c1 == 'A' && c2 == 'a') {
      S[head] = 'A';
      S[tail] = 'A';
    }
    else if (c1 == 'h' && c2 == 'h' || c1 == 'h' && c2 == 'H' || c1 == 'H' && c2 == 'h') {
      S[head] = 'H';
      S[tail] = 'H';
    }
    else if (c1 == 'i' && c2 == 'I' || c1 == 'I' && c2 == 'i') {
      S[head] = 'I';
      S[tail] = 'I';
    }
    else if (c1 == 'm' && c2 == 'M' || c1 == 'M' && c2 == 'm') {
      S[head] = 'M';
      S[tail] = 'M';
    }
    else if (c1 == 'o' && c2 == 'O' || c1 == 'O' && c2 == 'o') {
      S[head] = 'O';
      S[tail] = 'O';
    }
    else if (c1 == 't' && c2 == 't' || c1 == 't' && c2 == 'T' || c1 == 'T' && c2 == 't') {
      S[head] = 'T';
      S[tail] = 'T';
    }
    else if (c1 == 'u' && c2 == 'U' || c1 == 'U' && c2 == 'u') {
      S[head] = 'U';
      S[tail] = 'U';
    }
    else if (c1 == 'v' && c2 == 'V' || c1 == 'V' && c2 == 'v') {
      S[head] = 'V';
      S[tail] = 'V';
    }
    else if (c1 == 'w' && c2 == 'W' || c1 == 'W' && c2 == 'w') {
      S[head] = 'W';
      S[tail] = 'W';
    }
    else if (c1 == 'x' && c2 == 'X' || c1 == 'X' && c2 == 'x') {
      S[head] = 'X';
      S[tail] = 'X';
    }
    else if (c1 == 'y' && c2 == 'y' || c1 == 'y' && c2 == 'Y' || c1 == 'Y' && c2 == 'y') {
      S[head] = 'Y';
      S[tail] = 'Y';
    }
    else if (c1 == 'L' && c2 == 'L' || c1 == 'L' && c2 == 'l' || c1 == 'l' && c2 == 'L') {
      S[head] = 'l';
      S[tail] = 'l';
    }
    else if (c1 == 'N' && c2 == 'N' || c1 == 'N' && c2 == 'n' || c1 == 'n' && c2 == 'N') {
      S[head] = 'n';
      S[tail] = 'n';
    }
    else if (c1 == 'e' && c2 == '3') {
      S[head] = 'E';
    }
    else if (c1 == '3' && c2 == 'e') {
      S[tail] = 'E';
    }
    else if (c1 == 's' && c2 == '2') {
      S[head] = 'S';
    }
    else if (c1 == '2' && c2 == 's') {
      S[tail] = 'S';
    }
    else if (c1 == 'z' && c2 == '5') {
      S[head] = 'Z';
    }
    else if (c1 == '5' && c2 == 'z') {
      S[tail] = 'Z';
    }
    else if (c1 == 'B' && c2 == 'd' || c1 == 'b' && c2 == 'D' || c1 == 'B' && c2 == 'D') {
      S[head] = 'b';
      S[tail] = 'd';
    }
    else if (c1 == 'D' && c2 == 'b' || c1 == 'd' && c2 == 'B' || c1 == 'D' && c2 == 'B') {
      S[head] = 'd';
      S[tail] = 'b';
    }
    else if (c1 == 'P' && c2 == 'q' || c1 == 'p' && c2 == 'Q' || c1 == 'P' && c2 == 'Q') {
      S[head] = 'p';
      S[tail] = 'q';
    }
    else if (c1 == 'Q' && c2 == 'p' || c1 == 'q' && c2 == 'P' || c1 == 'Q' && c2 == 'P') {
      S[head] = 'q';
      S[tail] = 'p';
    }
    else if (c1 == 'R' && c2 == '7') {
      S[head] = 'r';
    }
    else if (c1 == '7' && c2 == 'R') {
      S[tail] = 'r';
    }
    else {
      possible = 0;
      break;
    }
    head++;
    tail--;
  }

  cout << (possible ? S : "-1") << "\n";
}
