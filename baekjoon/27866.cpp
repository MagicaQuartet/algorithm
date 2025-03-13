#include<iostream>
#include<string>
using namespace std;
string s;
int i;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s >> i;
    printf("%c\n", s[i - 1]);
}