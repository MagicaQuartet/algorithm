#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<limits>

using namespace std;

int checkIndex(int N, int M, int i, int j, int block[4][2]) {
	for (int b=0; b<4; b++) {
		if (i + block[b][0] >= N || j + block[b][1] >= M || j + block[b][1] < 0)
			return -1;
	}
	
	return 0;
}

int main() {
	int N, M, temp, ret;
	int blocks[19][4][2] = {
		{{0,0}, {0,1}, {0,2}, {0,3}},
		{{0,0}, {1,0}, {2,0}, {3,0}},
		{{0,0}, {0,1}, {1,0}, {1,1}},
		{{0,0}, {1,0}, {2,0}, {2,1}},
		{{0,0}, {1,0}, {1,-1}, {1,-2}},
		{{0,0}, {0,1}, {1,1}, {2,1}},
		{{0,0}, {0,1}, {0,2}, {1,0}},
		{{0,0}, {1,0}, {2,0}, {2,-1}},
		{{0,0}, {1,0}, {1,1}, {1,2}},
		{{0,0}, {0,1}, {1,0}, {2,0}},
		{{0,0}, {0,1}, {0,2}, {1,2}},
		{{0,0}, {1,0}, {1,1}, {2,1}},
		{{0,0}, {1,0}, {1,-1}, {2,-1}},
		{{0,0}, {0,1}, {1,0}, {1,-1}},
		{{0,0}, {0,1}, {1,1}, {1,2}},
		{{0,0}, {1,0}, {1,1}, {1,-1}},
		{{0,0}, {0,1}, {0,2}, {1,1}},
		{{0,0}, {1,0}, {2,0}, {1,-1}},
		{{0,0}, {1,0}, {2,0}, {1,1}},
	};
	
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
	
	ret = 0;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			for (int block=0; block<19; block++) {
				if (!checkIndex(N, M, i, j, blocks[block])) {
					temp = map[i+blocks[block][0][0]][j+blocks[block][0][1]] + \
						   map[i+blocks[block][1][0]][j+blocks[block][1][1]] + \
						   map[i+blocks[block][2][0]][j+blocks[block][2][1]] + \
						   map[i+blocks[block][3][0]][j+blocks[block][3][1]];
					
					if (ret < temp)
						ret = temp;
				}
			}
		}
	}
	
	cout << ret << endl;
	return 0;
}

/* 하드코딩의 힘이 느껴지십니까 */