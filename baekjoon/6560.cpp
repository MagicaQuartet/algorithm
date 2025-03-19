#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stack>
using namespace std;
string s;
int convert(char c) {
    return c - '0';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string d = "";
    while (1) {
        getline(cin, s);
        if (cin.eof()) {
            break;
        }
        cout << d;
        vector<set<int>> graph(51, set<int>());
        stack<int> stk;
        int tmp = 0;
        for (char c : s) {
            switch (c) {
            case '\n':
                break;
            case ' ':
            case '(':
            case ')':
                if (tmp > 0) {
                    if (!stk.empty()) {
                        graph[stk.top()].insert(tmp);
                        graph[tmp].insert(stk.top());
                    }
                    stk.push(tmp);
                    tmp = 0;
                }
                if (c == ')') {
                    stk.pop();
                }
                break;
            default:
                tmp = tmp * 10 + convert(c);
            }
        }
        while (1) {
            int num = 51;
            for (int i = 1; i <= 50; i++) {
                if (graph[i].size() == 1 && i < num) {
                    num = i;
                }
            }
            if (num == 51) {
                break;
            }
            int parent = *graph[num].begin();
            cout << parent << " ";
            graph[num].erase(parent);
            graph[parent].erase(num);
        }
        d = "\n";
    }
}
