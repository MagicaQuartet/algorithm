#include<cstdio>

using namespace std;

int main() {
	int answer = 5000;
	char c;
	do {
		c=getchar();
		if (c=='1')
			answer -= 500;
		else if (c=='2')
			answer -= 800;
		else if (c=='3')
			answer -= 1000;
	} while (c!='\n');
	printf("%d\n", answer);
	return 0;
}