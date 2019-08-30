#include<cstdio>

using namespace std;

int main() {
	int n;
	int x, y;
	int tilt;
	long long m;
	long long blocks;
	scanf("%d %lld", &n, &m);
	
	x = 1;
	y = 1;
	tilt = 0;
	
	while(n>1) {
		blocks = n*n/4;
		
		if (m>3*blocks) {
			if (tilt==0) {
				x += n-1;
				y += n/2-1;
				tilt = 3;
			}
			else if (tilt==1) {
				x += n/2-1;
				y += n-1;
				tilt = 2;
			}
			else if (tilt==3) {
				x -= n/2-1;
				y -= n-1;
				tilt = 0;
			}
			else {
				x -= n-1;
				y -= n/2-1;
				tilt = 1;
			}
			m -= 3*blocks;
		}
		else if (m>2*blocks) {
			if (tilt==0) {
				x += n/2;
				y += n/2;
			}
			else if (tilt==1) {
				x += n/2;
				y += n/2;
			}
			else if (tilt==3){
				x -= n/2;
				y -= n/2;
			}
			else {
				x -= n/2;
				y -= n/2;
			}
			m -= 2*blocks;
		}
		else if (m>blocks) {
			if (tilt==0) {
				y += n/2;
			}
			else if (tilt==1) {
				x += n/2;
			}
			else if (tilt==3) {
				x -= n/2;
			}
			else {
				y -= n/2;
			}
			m -= blocks;
		}
		else {
			if (tilt==0) {
				tilt = 1;
			}
			else if (tilt==1) {
				tilt = 0;
			}
			else if (tilt==3) {
				tilt = 2;
			}
			else {
				tilt = 3;
			}
		}
		n /= 2;
	}
	
	printf("%d %d\n", x, y);
	return 0;
}

/* 주어진 맵을 4등분해서 그 중 어떤 블록에 들어가는 지를 구하고 그 블록의 시작 지점으로 좌표를 옮긴다. 이를 계속 반복한다. */
/* 이 때, 각 블록이 어떻게 돌아가는 지도 정확히 파악해야 좌표를 올바르게 구할 수 있다. */