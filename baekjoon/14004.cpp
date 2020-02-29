#include<cstdio>
unsigned int A,B,C,D;main(){scanf("%u%u%u%u",&A,&B,&C,&D);printf("%u",(D+C)/(A-B));}

/*
  잘 생각해보면 등비수열의 합 공식을 이용한 문제라는 것을 알 수 있다.
  중간 계산 값이 자료형의 범위를 넘어가지 않게 하자. 결과값의 식을 정리하면 저렇게 나온다.
*/