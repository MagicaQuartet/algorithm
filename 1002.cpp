#include<cstdio>

using namespace std;

int main() {
	int T;
	int x1, y1, r1, x2, y2, r2;
	int dx, dy, dd;
	int answer;
	
	scanf("%d", &T);
	
	while(T--) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		dx = x2-x1;
		dy = y2-y1;
		dd = dx*dx+dy*dy;
		
		if (dd == 0) {
			answer = (r1==r2) ? -1 : 0;
		}
		else if (dd < (r2-r1)*(r2-r1)) {
			answer = 0;
		}
		else if (dd == (r2-r1)*(r2-r1)) {
			answer = 1;
		}
		else if (dd < (r2+r1)*(r2+r1)) {
			answer = 2;
		}
		else if (dd == (r2+r1)*(r2+r1)) {
			answer = 1;
		}
		else {
			answer = 0;
		}
		
		printf("%d\n", answer);
	}
	return 0;
}