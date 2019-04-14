#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<limits>

using namespace std;

int main() {
	int N, M, temp, ret;
	cin.sync_with_stdio(false);
	
	cin >> N >> M;
	vector<vector<int>> map;
		
	for (int i=0; i<N; i++) {
		map.push_back(vector<int>());
		for (int j=0; j<M; j++) {
			cin >> temp;
			map[i].push_back(temp);
		}
	}
	
	
	
	return 0;
}