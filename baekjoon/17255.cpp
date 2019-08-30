#include<cstdio>
#include<vector>

using namespace std;

int subnumber(const vector<int>& num, int start, int end) {
	int result = 0;
	int multiplier = 1;
	
	for (int i=end; i>=start; i--) {
		result += num[i]*multiplier;
		multiplier *= 10;
	}
	
	return result;
}

int main() {
	int N, length;
	vector<int> num;
	vector<int> cnt;
	scanf("%d", &N);
	
	if (N == 0) {
		printf("1\n");
	}
	else {
		while (N>0) {
			num.push_back(N%10);
			cnt.push_back(1);
			N /= 10;
		}
	
		length = num.size();
	
		for (int i=0; i<length; i++) {
			for (int j=0; j<length-i-1; j++) {
				if (subnumber(num, j, j+i) != subnumber(num, j+1, j+i+1)) {
					cnt[j] = cnt[j] + cnt[j+1];
				}
			}
		}
	
		printf("%d\n", cnt[0]);
	}
	return 0;
}

/* 길이가 1...n인 부분을 만드는 방법의 수를 순차적으로 구한다.
 * 인접한 길이 k인 두 부분을 만드는 방법의 수가 각각 a, b이면 두 부분을 합쳐서 만들 수 있는 경우의 수는 a+b이다. 
 * 단, 두 부분이 같은 수일 경우 (예: 9111을 만드는 과정에서 k=2일 때 11이 인접하는 경우가 있다.), 그 두 부분은 필연적으로 모든 자릿수가 같은 숫자로 이루어져 있으며
 * (증명: 두 부분수는 abcde, bcdef의 형태이고 abcde==bcdef이므로 a==b==c==d==e==f가 된다.)
 * 따라서 그 두 부분을 합쳐서 만드는 길이 k+1인 부분도 모든 자릿수가 같은 숫자로 이루어져 있어 경우의 수가 1로 유지된다. */