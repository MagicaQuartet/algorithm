#include<cstdio>

using namespace std;

int main() {
	int left = 0;
	int right = 0;
	int changed = 0;
	char c = '!';
	
	while(c!='\n') {
		c = getchar();
		if (c=='@') {
			if (!changed) {
				left++;
			}
			else {
				right++;
			}
		}
		else if (c=='(') {
			changed = 1;
		}
	}
	printf("%d %d\n", left, right);
	return 0;
}

/* 생각을 비우고 풀어도 된다 */