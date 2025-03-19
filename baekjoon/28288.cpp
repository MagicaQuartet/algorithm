#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int N;
int cnt[5];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(cnt, 0, sizeof(cnt));
    string s;
    int maxCnt = -1;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < 5; j++) {
            if (s[j] == 'Y') {
                cnt[j]++;
                if (cnt[j] > maxCnt) {
                    maxCnt = cnt[j];
                }
            }
        }
    }
    string d = "";
    for (int i = 0; i < 5; i++) {
        if (maxCnt == cnt[i]) {
            cout << d << i + 1;
            d = ",";
        }
    }
    cout << "\n";
}