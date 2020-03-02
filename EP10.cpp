/*************************************************************************
	> File Name: EP10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月19日 星期四 19时01分00秒
 ************************************************************************/
#include <stdio.h>
#define max_n 2000000

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }

}
int main() {
    init();
    long long sun = 0;
    for(int i = 1; i <= prime[0]; i++) {
        sun += prime[i];
    }
    printf("%lld\n", sun);
    return 0;
}
