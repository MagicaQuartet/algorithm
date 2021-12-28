#include<cstdio>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
#define ll long long
#define vi vector<int>
int N, a, b, c;
ll _abs(ll n) {
    return n >= 0 ? n : -n;
}
int main() {
    scanf("%d", &N);
    vi acid, base;
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
    sort(acid.begin(), acid.end());
    sort(base.begin(), base.end());
    ll sum = 3000000000;
    if (acid.size() >= 3) {
        ll _sum = acid[0] + acid[1] + acid[2];
        if (_sum < sum) {
            sum = _sum;
            a = acid[0];
            b = acid[1];
            c = acid[2];
        }
    }
    if (base.size() >= 3) {
        ll _sum = -base[base.size() - 1] - base[base.size() - 2] - base[base.size() - 3];
        if (_sum < sum) {
            sum = _sum;
            a = base[base.size() - 3];
            b = base[base.size() - 2];
            c = base[base.size() - 1];
        }
    }
    if (acid.size() >= 2 && base.size() >= 1) {
        for (int i = 0; i < acid.size(); i++) {
            for (int j = i + 1; j < acid.size(); j++) {
                ll acids = acid[i] + acid[j];
                vi::iterator lb = lower_bound(base.begin(), base.end(), -acids);
                if (lb != base.end() && _abs(acids + *lb) < sum) {
                    sum = _abs(acids + *lb);
                    a = *lb;
                    b = acid[i];
                    c = acid[j];
                }
                if (lb != base.begin() && _abs(acids + *prev(lb)) < sum) {
                    sum = _abs(acids + *prev(lb));
                    a = *prev(lb);
                    b = acid[i];
                    c = acid[j];
                }
            }
        }
    }
    if (base.size() >= 2 && acid.size() >= 1) {
        for (int i = 0; i < base.size(); i++) {
            for (int j = i + 1; j < base.size(); j++) {
                ll bases = base[i] + base[j];
                vi::iterator lb = lower_bound(acid.begin(), acid.end(), -bases);
                if (lb != acid.end() && _abs(bases + *lb) < sum) {
                    sum = _abs(bases + *lb);
                    a = base[i];
                    b = base[j];
                    c = *lb;
                }
                if (lb != acid.begin() && _abs(bases + *prev(lb)) < sum) {
                    sum = _abs(bases + *prev(lb));
                    a = base[i];
                    b = base[j];
                    c = *prev(lb);
                }
            }
        }
    }

    printf("%d %d %d\n", a, b, c);
}
