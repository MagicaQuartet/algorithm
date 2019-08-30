#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	int T, N, M;
	
	cin >> T;
	
	for (int t=0; t<T; t++) {
		cin >> N >> M;
		
		queue<int> queue;
		priority_queue<int> num;
		int cnt=1;
		
		for (int i=0; i<N; i++) {
			int temp;
			cin >> temp;
			queue.push(temp);
			num.push(temp);
		}
		
		while(!queue.empty()) {
			if (queue.front() == num.top()) {
				queue.pop();
				num.pop();
				
				if (M == 0) {
					cout << cnt << endl;
					break;
				}
				else {
					M--;
					cnt++;
				}
			}
			else {
				int temp = queue.front();
				queue.pop();
				queue.push(temp);
				
				if (M == 0)
					M = queue.size() - 1;
				else
					M--;
			}
		}
	}
	
	return 0;
}

/* N의 크기가 크지 않아서 그냥 시뮬레이션을 돌려도 충분히 통과한다 */