#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int main() {
	int N, temp, cnt;
	long min;
	vector<int> o;
	vector<int> d;
	vector<int> r;
	vector<long> dp;
	
	cin.sync_with_stdio(false);
	cin >> N;
	
	for (int i=0; i<N; i++) {
		cin >> temp;
		o.push_back(temp);
	}
	
	for (int i=0; i<N; i++) {
		cin >> temp;
		d.push_back(temp);
	}
	
	for (int i=0; i<N; i++) {
		r.push_back(o[i]-d[i]);
	}
	
	dp.push_back(r[0]);
	min = numeric_limits<long>::max();
	for (int i=1; i<N; i++) {
		dp.push_back(dp[i-1] + r[i]);
		if (dp[i] < min) {
			min = dp[i];
		}
	}
	
	cnt = 0;
	if (min >= 0)
		cnt += 1;
	
	for (int i=0; i<N-1; i++) {
		min -= r[i];
		if (min >= 0) {
			cnt += 1;
		}
	}
	
	cout << cnt << endl;
	return 0;
}

/* 한 주유소에서 채울 수 있는 기름의 양과 그 주유소에서 다음 주유소까지 가는 데에 소모되는 기름의 양을 묶어서
   한 주유소에서 다음 주유소에 갈 때 까지의 기름의 증감으로 나타낼 수 있다 이를 r이라 하자.
   이 값을 모두 구한 다음, 한 주유소를 잡고 그 주유소에서 시작하여 한 바퀴 도는 동안 각 주유소에서 남는 기름의 양을 음수 상관없이 구한다. 이를 dp라 하자.
   시작 주유소를 i번째에서 i+1번째로 한 칸 씩 넘길 때마다 dp의 원소들에서 r[i]을 빼주면 i+1번째 주유소에서 시작하여 한 바퀴를 돌았을 때의 dp가 된다.
   이를 이용해 모든 주유소에서 시작하는 경우를 linear하게 구하고, 이 중 dp의 원소 중 음수가 하나도 없는 경우를 세면 답을 구할 수 있다. */