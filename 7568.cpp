#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<functional>

using namespace std;

int main() {
	int N, x, y;
	vector<int> weight;
	vector<int> height;
	
	cin.sync_with_stdio(false);
	cin >> N;
	
	for (int i=0; i<N; i++) {
		cin >> x >> y;
		weight.push_back(x);
		height.push_back(y);
	}
	
	for (int i=0; i<N; i++) {
		int cnt = 0;
		for (int j=0; j<N; j++) {
			if (i==j)
				continue;
			
			if (weight[i] < weight[j] && height[i] < height[j])
				cnt += 1;
		}
		cout << cnt+1 << " ";
	}
	cout << endl;
	
	return 0;
}

/* 자기보다 덩치 큰 사람이 k명이면 이 사람의 등수는 k+1등이다. 이 점을 잊지 않고 등수를 이상하게 세지 말자. */