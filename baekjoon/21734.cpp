#include<iostream>
#include<string>
using namespace std;
string s;
int sum(char c) {
    int ret = 0;
    while (c) {
        ret += c % 10;
        c /= 10;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (auto c : s) {
        for (int i = 0; i < sum(c); i++) {
            printf("%c", c);
        }
        printf("\n");
    }
}