/*************************************************************************
	> File Name: EP12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月26日 星期四 19时48分52秒
 ************************************************************************/

#include <stdio.h>
#define max_n 100000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                f[prime[j] * i] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[prime[j] * i] = cnt[i] + 1;
                break;
            } else {
                f[prime[j] * i] = f[prime[j]] * f[i];
                cnt[prime[j] * i] = 1;
            }
        }
    }
    return ;
}

int main() {
    init();
    long long  f_max = 0, n = 1;
    while (1) {
        if (n & 1) {
            f_max = f[n] * f[(n + 1) >> 1];
        } else {
            f_max = f[n >> 1] * f[n + 1];
        }
        if (f_max > 500) break;
        n += 1;
    }
    printf("%lld\n", n * (n + 1) / 2);
    return 0;
}
