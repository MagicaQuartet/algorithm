#include<cstdio>

using namespace std;

int main() {
	int key = 'C';
	char c;
	
	while (true) {
		c=getchar();
		if (c=='\n')
			break;
		
		if (key=='C') {
			key = 'C'^c;
		}
		printf("%c", c^key);
	}
	printf("\n");
	return 0;
}

/* 처음에 while문을 잘못 짜서 c에 \n이 마지막에 들어가는 게 문제가 됐었음 */