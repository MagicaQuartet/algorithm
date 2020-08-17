#include<cstdio>
int a,b,c,d,e,f;
int main(){scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);int det=a*e-b*d;printf("%d %d\n",(e*c-b*f)/det,(-c*d+a*f)/det);}