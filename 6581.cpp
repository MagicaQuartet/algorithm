// Baekjoon Online Judge #6581
// (Implementation)

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	char c;
	bool tag = false, whitespace = false;
	char line[81], word[81];
	int line_cnt = 0, word_cnt = 0;

	while((c=getchar()) != EOF) {
		if (!tag) {
			if (c == ' ' || c == '\n' || c == '\t') {
				if (whitespace) {
					line[line_cnt] = ' ';
				}
				else {
					if (line_cnt + word_cnt >= 80) {
						if (line_cnt != 0 && line[line_cnt-1] == ' ')
							line[line_cnt-1] = '\0';
						else
							line[line_cnt] = '\0';
						// cout << "\"" << line << "\"" << endl;
	 					cout << line << endl;
						line_cnt = 0;
						line[0] = '\0';
					}

					for (int i = 0; i < word_cnt; i++) {
						line[line_cnt] = word[i];
						line_cnt++;
					}

					word_cnt = 0;
					word[0] = '\0';

					if (line_cnt > 0) {
						line[line_cnt] = ' ';
						line_cnt++;
					}
					whitespace = true;
				}
			}
			else if (c == '<') {
				tag = true;
				if (line_cnt > 0) {
					if (line[line_cnt-1] = ' ')
						line[line_cnt-1] = '\0';
					else 
						line[line_cnt] = '\0';
				}
				whitespace = false;
			}
			else {
				whitespace = false;

				word[word_cnt] = c;
				word_cnt++;
			}
		}
		else {
			if (c == '>') {
				tag = false;
			}
			else if (c == 'r') {
				continue;
			}
			else if (c == 'b') {
				// cout << "\"" << line << "\"" << endl;
	 			cout << line << endl;
				line_cnt = 0;
				line[0] = '\0';
			}
			else {
				if (line_cnt > 0) {
					// cout << "\"" << line << "\"" << endl;
	 				cout << line << endl;
					line_cnt = 0;
					line[0] = '\0';
				}

				cout << "--------------------------------------------------------------------------------" << endl;
			}
		}
	}

	if (line_cnt + word_cnt >= 80) {
		if (line_cnt != 0 && line[line_cnt-1] == ' ')
			line[line_cnt-1] = '\0';
		else
			line[line_cnt] = '\0';
		// cout << "\"" << line << "\"" << endl;
	 	cout << line << endl;
		line_cnt = 0;
	}

	for (int i = 0; i < word_cnt; i++) {
		line[line_cnt] = word[i];
		line_cnt++;
	}

	if (line_cnt != 0 && line[line_cnt-1] == ' ')
		line[line_cnt-1] = '\0';
	else
		line[line_cnt] = '\0';
	// cout << "\"" << line << "\"" << endl;
	 cout << line << endl;

	return 0;
}

/*
그냥...잘...해라...
 */