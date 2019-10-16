#include <cstdio>

using namespace std;

int main() {
	char c;
	char A = 65;
	int result = 0;
	
	scanf("%c", &c);
	while (c >= A) {
		if (c < A + 3) {
			result += 3;
		}
		else if (c < A + 6) {
			result += 4;
		}
		else if (c < A + 9) {
			result += 5;
		}
		else if (c < A + 12) {
			result += 6;
		}
		else if (c < A + 15) {
			result += 7;
		}
		else if (c < A + 19) {
			result += 8;
		}
		else if (c < A + 22) {
			result += 9;
		}
		else {
			result += 10;
		}
		scanf("%c", &c);
	}
	
	printf("%d\n", result);
}