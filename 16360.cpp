#include<iostream>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	while (n--) {
		string s;
		cin >> s;
		
		if (s[s.size()-1] == 'a') {
			s.push_back('s');
		}
		else if (s[s.size()-1] == 'i' || s[s.size()-1] == 'y') {
			s[s.size()-1] = 'i';
			s.append("os");
		}
		else if (s[s.size()-1] == 'l') {
			s.append("es");
		}
		else if (s[s.size()-1] == 'n') {
			s[s.size()-1] = 'a';
			s.append("nes");
		}
		else if (s[s.size()-2] == 'n' && s[s.size()-1] == 'e') {
			s[s.size()-2] = 'a';
			s[s.size()-1] = 'n';
			s.append("es");
		}
		else if (s[s.size()-1] == 'o') {
			s.push_back('s');
		}
		else if (s[s.size()-1] == 'r') {
			s.append("es");
		}
		else if (s[s.size()-1] == 't') {
			s.append("as");
		}
		else if (s[s.size()-1] == 'u') {
			s.push_back('s');
		}
		else if (s[s.size()-1] == 'v') {
			s.append("es");
		}
		else if (s[s.size()-1] == 'w') {
			s.append("as");
		}
		else {
			s.append("us");
		}
		
		cout << s << endl;
	}
}