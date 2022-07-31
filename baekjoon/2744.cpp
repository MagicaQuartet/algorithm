#include<string>
#include<iostream>
using namespace std;
string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (auto c : s) {
        if ('a' <= c && c <= 'z') {
            cout << char('A' + (c - 'a'));
        }
        else {
            cout << char('a' + (c - 'A'));
        }
    }
    cout << "\n";
}