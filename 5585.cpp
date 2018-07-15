// Baekjoon Online Judge #5585
// (Greedy)

#include <iostream>

using namespace std;

int main() {
	int n, change, cnt = 0;
	cin >> n;

	change = 1000 - n;

	cnt += change/500;
	change = change%500;

	cnt += change/100;
	change = change%100;

	cnt += change/50;
	change = change%50;

	cnt += change/10;
	change = change%10;

	cnt += change/5;
	change = change%5;

	cnt += change;

	cout << cnt << endl;
	return 0;
}

/*
액수가 큰 동전부터 거스름돈으로 얼마까지 줄 수 있는 지를 센다. 큰 동전을 최대한 많이 주어야 거스름돈을 이루는 동전의 수가 적어진다.
 */