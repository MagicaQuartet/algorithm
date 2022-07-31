#include<ctime>
#include<cstdio>

int main() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    printf("%04d-%02d-%02d\n", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
}
