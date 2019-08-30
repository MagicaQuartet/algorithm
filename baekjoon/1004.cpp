#include<cstdio>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	
	while(T--) {
		int x1, y1, x2, y2, n;
		int cnt = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		
		while(n--) {
			int cx, cy, r;
			int lhs = 0, rhs = 0;
			int dl, dr;
			scanf("%d %d %d", &cx, &cy, &r);
			
			dl = (cx-x1)*(cx-x1)+(cy-y1)*(cy-y1);
			dr = (cx-x2)*(cx-x2)+(cy-y2)*(cy-y2);
			
			if (r*r > dl) {
				lhs = 1;
			}
			else if (r*r < dl) {
				lhs = -1;
			}
			
			if (r*r > dr) {
				rhs = 1;
			}
			else if (r*r < dr) {
				rhs = -1;
			}
			
			if (lhs*rhs == -1) {
				cnt++;
			}
		}
		
		printf("%d\n", cnt);
	}
	return 0;
}

/* 각각의 원에 대해 두 지점이 서로 다른 영역(하나는 내부 하나는 외부)에 존재하는 경우의 수를 세면 된다. 두 점이 같은 영역에 있거나 둘 중 한 점이 원 위에 존재하면 진입/이탈이 불필요하다. */