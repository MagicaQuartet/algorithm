#include<string>
#include<iostream>
#include <iomanip>
using namespace std;
string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    double score;
    if (s[0] == 'F') {
        score = 0.0;
    }
    else {
        score = 4.0 - (s[0] - 'A');
        if (s[1] == '+') {
            score += 0.3;
        }
        else if (s[1] == '-') {
            score -= 0.3;
        }
    }
    cout << fixed << setprecision(1);
    cout << score << "\n";
}