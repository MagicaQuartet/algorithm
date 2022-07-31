#include<string>
#include<iostream>
using namespace std;
int N;
string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        cout << s.front() << s.back() << "\n";
    }
}