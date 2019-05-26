#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int base, multiplier = 1;
	int result = 0;
	char c='0';
	vector<char> num;
	
	c = getchar();
	while (c!=' ') {
		num.push_back(c);
		c = getchar();
	}
	scanf("%d", &base);
	
	while (!num.empty()) {
		char _c = num.back();
		result += (_c <= 57 ? _c-48 : _c-55)*multiplier;
		num.pop_back();
		multiplier *= base;
	}
	printf("%d\n", result);
	return 0;
}

/* 직접 한땀한땀 바꾸는 방식을 썼는데 C++에 string을 long integer로 바꾸는 strtol 이라는 함수가 있다. 와! */