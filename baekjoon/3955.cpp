#include<cstdio>
#define ll long long

int t, K, C;

int main() {
  scanf("%d", &t);

  for (int i=0; i<t; i++) {
    scanf("%d %d", &K, &C);
    ll s0, t0, r0, s1, t1, r1, tmp, q;

    s0 = 1;
    t0 = 0;
    r0 = -K;
    s1 = 0;
    t1 = 1;
    r1 = C;

    while (r1 != 0) {
      q = r0 / r1;

      tmp = r0 - r1*q;
      r0 = r1;
      r1 = tmp;

      tmp = s0 - s1 * q;
      s0 = s1;
      s1 = tmp;
      
      tmp = t0 - t1 * q;
      t0 = t1;
      t1 = tmp;
    }

    if (r0 != 1 && r0 != -1) {
      printf("IMPOSSIBLE\n");
    }
    else {
      ll x = s0*1/r0;
      ll y = t0*1/r0;

      while(y <= 0 || x <= 0) {
        x += C;
        y -= -K;
        if (y > 1000000000) {
          break;
        }
      }

      if (y > 1000000000) {
        printf("IMPOSSIBLE\n");
      }
      else {
        printf("%lld\n", y);
      }
    }
  }
}

/*
  확장 유클리드 호제법 진짜 헷갈리네ㅠㅠㅠㅠㅠ 수학 진짜 어렵다....나중에 다시 봐야 제대로 이해할 듯.........
*/