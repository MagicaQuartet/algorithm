#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, num, ret;
	vector<int> trees;
	
	
	cin.sync_with_stdio(false);
	cin >> N;
	
	for (int i=0; i<N; i++) {
		cin >> num;
		trees.push_back(num);
	}
	
	ret = 0;
	for (int i=1; i<N-2; i++) {
		int _ret = 0;
		int group1 = 1;
		for (int tree=0; tree<i; tree++) {
			group1 *= trees[tree];
		}
		_ret += group1;
		for (int j=i+1; j<N-1; j++) {
			int group2 = 1;
			for (int tree=i; tree<j; tree++) {
				group2 *= trees[tree];
			}
			_ret += group2;
			for (int k=j+1; k<N; k++) {
				int group3 = 1;
				for (int tree=j; tree<k; tree++) {
					group3 *= trees[tree];
				}
				_ret += group3;
				
				int group4 = 1;
				for (int tree=k; tree<N; tree++) {
					group4 *= trees[tree];
				}
				_ret += group4;
				
				if (ret < _ret) {
					ret = _ret;
				}
				
				_ret -= group4;
				_ret -= group3;
			}
			
			_ret -= group2;
		}
		
		_ret -= group1;
	}
	
	cout << ret << endl;
	return 0;
}

/* input 크기가 작아서 그냥 막 짜도 된다. DP를 쓰면 더 빨리 되기는 할 것 */