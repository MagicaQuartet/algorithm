// Baekjoon Online Judge #11497
// (Daejeon Regional)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T, N;
	cin >> T;

	for (int test = 0; test < T; test++) {
		cin >> N;

		vector<int> input;
		vector<int> seq;

		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			input.push_back(temp);
			seq.push_back(0);
		}

		sort(input.begin(), input.end());

		seq[0] = input[0];
		seq[N-1] = input[1];
		int max_diff = seq[0] - seq[N-1] >= 0 ? seq[0] - seq[N-1] : seq[N-1] - seq[0];

		for (int i = 2; i < N; i+=2) {
			int prev_lhs = seq[i/2-1], prev_rhs = seq[N-i/2];
			
			if (i != N-1) {
				int curr1 = input[i], curr2 = input[i+1];
				int diff1 = max(curr1-prev_lhs, curr2-prev_rhs);
				int diff2 = max(curr2-prev_lhs, curr1-prev_rhs);

				if (diff1 < diff2) {
					seq[i/2] = curr1;
					seq[N-1-i/2] = curr2;
					if (max_diff < diff1)
						max_diff = diff1;
				}
				else {
					seq[i/2] = curr2;
					seq[N-1-i/2] = curr1;
					if (max_diff < diff2)
						max_diff = diff2;	
				}
			}
			else {
				int curr = input[i];
				int diff = max(curr-prev_lhs, curr-prev_rhs);

				if (max_diff < diff)
					max_diff = diff;
			}
		}

		cout << max_diff << endl;
	}

	return 0;
}