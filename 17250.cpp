#include<vector>
#include<cstdio>

using namespace std;

int getAncestor(const vector<int>& parent, int i) {
	if (i == parent[i]) {
		return i;
	}
	return getAncestor(parent, parent[i]);
}

int main() {
	int N, M;
	vector<int> population;
	vector<int> parent;
	scanf("%d %d", &N, &M);
	
	for (int i=0; i<N; i++) {
		int p;
		scanf("%d", &p);
		population.push_back(p);
		parent.push_back(i);
	}
	
	for (int i=0; i<M; i++) {
		int src, dest;
		scanf("%d %d", &src, &dest);
		
		int srcAncestor = getAncestor(parent, src-1);
		int destAncestor = getAncestor(parent, dest-1);
		int less = srcAncestor < destAncestor ? srcAncestor : destAncestor;
		int greater = srcAncestor >= destAncestor ? srcAncestor : destAncestor;
		
		if (srcAncestor != destAncestor) {
			parent[greater] = less;
			population[less] = population[less] + population[greater];
		}
		
		printf("%d\n", population[less]);
	}
	return 0;
}