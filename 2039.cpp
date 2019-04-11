#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	
	vector<int> dwarf;
	int sum=0;
	int badDwarf1=0, badDwarf2=0;
	
	for (int i=0; i<9; i++) {
		int temp;
		cin >> temp;
		dwarf.push_back(temp);
		sum += temp;
	}
	
	sort(dwarf.begin(), dwarf.end());
	
	for (int i=0; i<8; i++) {
		for (int j=i; j<9; j++) {
			if (sum - dwarf[i] - dwarf[j] == 100) {
				badDwarf1 = i;
				badDwarf2 = j;
				break;
			}
		}
		
		if (badDwarf2 > 0)
			break;
	}
	
	for (int i=0; i<9; i++) {
		if (i == badDwarf1 || i == badDwarf2)
			continue;
		cout << dwarf[i] << endl;
	}
	
	return 0;
}

/* 9명의 난쟁이 중 2명만 거르면 되기 때문에 간단하게 알아낼 수 있음 */