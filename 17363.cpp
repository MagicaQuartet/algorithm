#include<cstdio>
#include<vector>

using namespace std;

char rotate(char c) {
	switch (c) {
		case '-':
			return '|';
			break;
		case '|':
			return '-';
			break;
		case '\\':
			return '/';
			break;
		case '/':
			return '\\';
			break;
		case '^':
			return '<';
			break;
		case '<':
			return 'v';
			break;
		case 'v':
			return '>';
			break;
		case '>':
			return '^';
			break;
		default:
			return c;
	}
}

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	vector<vector<char>> milk;
	
	for (int i=0; i<m; i++) {
		milk.push_back(vector<char>(n, 0));
	}
	
	for (int i=0; i<n; i++) {
		char c;
		for (int j=0; j<m; j++) {
			do {
				c=getchar();
			} while (c=='\n');
			milk[j][i] = rotate(c);
		}
	}
	
	for (int i=m-1; i>=0; i--) {
		for (int j=0; j<n; j++) {
			printf("%c", milk[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/* milk의 row 순서가 뒤집어져 있는데 왜 그렇지... */