#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, M, ret;
	char cell;
	vector<vector<char>> board;
	
	cin.sync_with_stdio(false);
	cin >> N >> M;
	
	for (int i=0; i<N; i++) {
		board.push_back(vector<char>());
		for (int j=0; j<M; j++) {
			cin >> cell;
			
			board[i].push_back(cell);
		}
	}
	
	ret = 64;
	
	for (int i=0; i<N-7; i++) {
		for (int j=0; j<M-7; j++) {
			int white_case = 0, black_case = 0, _ret;
			for (int x=0; x<8; x++) {
				for (int y=0; y<8; y++) {
					if ((x+y)%2 == 0) {
						if (board[i+x][j+y] == 'B')
							white_case++;
						else
							black_case++;
					}
					else {
						if (board[i+x][j+y] == 'B')
							black_case++;
						else
							white_case++;
					}
				}
			}
			
			_ret = white_case < black_case ? white_case : black_case;
			
			if (_ret < ret) {
				ret = _ret;
			}
		}
	}
	
	cout << ret << endl;
}

/* 크기가 작아서 그냥 무작정 for문을 돌려도 된다. O(N+M)으로 풀기 위해 DP도 충분히 이용가능함. */