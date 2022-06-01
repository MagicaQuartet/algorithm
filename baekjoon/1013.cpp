#include<iostream>
#include<string>
using namespace std;
enum State {
    STATE_INIT,
    STATE_RIGHT,
    STATE_LEFT_1,
    STATE_LEFT_10,
    STATE_LEFT_100,
    STATE_LEFT_1001,
    STATE_AMB_1,
    STATE_AMB_0,
    STATE_INVALID,
};
int T;
string s;

State transition(State current, char c) {
    switch (current) {
    case STATE_INIT:
        return c == '0' ? STATE_RIGHT : STATE_LEFT_1;
    case STATE_RIGHT:
        if (c == '1') { return STATE_INIT; }
        break;
    case STATE_LEFT_1:
        if (c == '0') { return STATE_LEFT_10; }
        break;
    case STATE_LEFT_10:
        if (c == '0') { return STATE_LEFT_100; }
        break;
    case STATE_LEFT_100:
        return c == '0' ? STATE_LEFT_100 : STATE_LEFT_1001;
    case STATE_LEFT_1001:
        return c == '0' ? STATE_RIGHT : STATE_AMB_1;
    case STATE_AMB_1:
        return c == '0' ? STATE_AMB_0 : STATE_AMB_1;
    case STATE_AMB_0:
        return c == '0' ? STATE_LEFT_100 : STATE_INIT;
    default:
        return STATE_INVALID;
    }
    return STATE_INVALID;
}

bool isCompleteState(State current) {
    switch (current) {
    case STATE_INIT:
    case STATE_LEFT_1001:
    case STATE_AMB_1:
        return true;
        break;
    default:
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> s;
        State current = STATE_INIT;
        bool completed = false;
        for (auto c : s) {
            current = transition(current, c);
            if (current == STATE_INVALID) {
                break;
            }
            completed = isCompleteState(current);
        }
        cout << (current == STATE_INVALID || !completed ? "NO\n" : "YES\n");
    }
}