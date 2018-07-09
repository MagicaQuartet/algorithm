// Baekjoon Online Judge #1350
// (Math)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, filesize, cluster;
	vector<int> filesizes;
	long long size = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> filesize;
		filesizes.push_back(filesize);
	}

	cin >> cluster;

	for (vector<int>::iterator it=filesizes.begin(); it!=filesizes.end(); ++it){
		size += (*it/cluster + (*it % cluster > 0 ? 1 : 0)) * cluster;
	}

	cout << size << endl;
	return 0;
}

/*
각 파일사이즈를 따로 저장한 뒤 각 파일이 필요로 하는 클러스터 수를 합한다.
 */