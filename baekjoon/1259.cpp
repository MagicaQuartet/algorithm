#include <cstdio>
#include <vector>

using namespace std;

int main() {
  vector<int> digits;
  int num;
  
  while (true) {
    int isPalindrome = 1;
    scanf("%d", &num);
    if (num == 0) break;
    
    while (num > 0) {
      digits.push_back(num % 10);
      num /= 10;
    }
    
    for (int i=0; i<digits.size(); i++) {
      if (i > digits.size() - 1 - i) break;
      if (digits[i] != digits[digits.size()-1-i]) {
        isPalindrome = 0;
        break;
      }
    }
    
    if (isPalindrome) printf("yes\n");
    else printf("no\n");
    digits.clear();
  }
  return 0;
}

/* 팰린드롬 연습 */