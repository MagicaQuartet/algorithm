#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int N, Q, cow, trick, sum;
	vector<int> cows;
	vector<int> groups;
	
	scanf("%d %d", &N, &Q);
	
	groups.push_back(1);
	sum = 1;
	for (int i=0; i<N; i++) {
		scanf("%d", &cow);
		cows.push_back(cow);
		if (i < 4) {
			groups[0] *= cow;
			sum *= cow;
		}
		else {
			groups.push_back(groups[i-4]/cows[i-4]*cow);
			sum += groups[i-3];
		}
	}
	if (N > 4) {
		for (int i=0; i<3; i++) {
			groups.push_back(groups[N-4+i]/cows[N-4+i]*cows[i]);
			sum += groups[N-3+i];
		}
	}
		
	for (int i=0; i<Q; i++) {
		scanf("%d", &trick);
		trick -= 1;
		
		if (N > 4) {
			for (int i=0; i<4; i++) {
				sum -= 2*groups[(N+trick-3+i)%N];
				groups[(N+trick-3+i)%N] *= -1;
			}
		}
		else {
			sum *= -1;
		}
		
		printf("%d\n", sum);
	}
	return 0;
}

/* DP를 이용해서 열심히 빠르게 만들어놨더니 iostream 썼다고 느려져서 초견 클리어 못했다. cstdio를 쓰자. */