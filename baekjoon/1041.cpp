#include<cstdio>
#include<algorithm>
using namespace std;
int a, b, c, d, e, f;
long long N;
int main() {
  int oneMin, twoMin, threeMin;
  scanf("%lld%d%d%d%d%d%d", &N, &a, &b, &c, &d, &e, &f);
  
  oneMin = min(min(min(a, b), c), min(min(d, e), f));
  // ac, bc, cf, ce, ad, bd, df, de, ab, bf, ef, ae
  twoMin = min(min(min(min(a+c, b+c), min(c+f, c+e)), min(min(a+d, b+d), min(d+f, d+e))), min(min(a+b, b+f), min(e+f, a+e)));
  // abc, bcf, cef, ace, abd, bdf, def, ade
  threeMin = min(min(min(a+b+c, b+c+f), min(c+e+f, a+c+e)), min(min(a+b+d, b+d+f), min(d+e+f, a+d+e)));
  
  long long ret;
  if (N == 1) {
    int hidden = max(max(max(a, b), max(c, d)), max(e, f));
    ret = a+b+c+d+e+f-hidden;
  }
  else if (N == 2) {
    ret = threeMin*4 + twoMin*4;
  }
  else {
    ret = ((N-2)*(N-2)*5+(N-2)*4)*oneMin + ((N-2)*8+4)*twoMin + 4*threeMin;
  }
  printf("%lld\n", ret);
}

/*
  결과값은 물론이고, 계산 중간값도 int의 범위를 넘을 수 있으므로 유의
*/