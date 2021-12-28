#include<cstdio>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
#define vi vector<int>
int N;
int abs(int n) {
    return n >= 0 ? n : -n;
}
int main() {
    scanf("%d", &N);
    vi acid;
    vi base;
    while (N--) {
        int num;
        scanf("%d", &num);
        if (num < 0) {
            base.push_back(num);
        }
        else {
            acid.push_back(num);
        }
    }

    int ans = 2000000000;
    int a, b;
    if (acid.size() != 0 && base.size() != 0) {
        for (auto n : base) {
            vi::iterator lb = lower_bound(acid.begin(), acid.end(), -n);
            if (lb != acid.end() && abs(n + *lb) < ans) {
                ans = abs(n + *lb);
                a = *lb;
                b = n;
            }
            if (lb != acid.begin() && abs(n + *prev(lb)) < ans) {
                ans = abs(n + *prev(lb));
                a = *prev(lb);
                b = n;
            }
        }
    }
    if (acid.size() >= 2 && acid[0] + acid[1] < ans) {
        ans = acid[0] + acid[1];
        b = acid[0];
        a = acid[1];
    }
    if (base.size() >= 2 && -base[base.size() - 1] - base[base.size() - 2] < ans) {
        ans = -base[base.size() - 1] - base[base.size() - 2];
        b = base[base.size() - 2];
        a = base[base.size() - 1];
    }
    printf("%d %d\n", b, a);
}
