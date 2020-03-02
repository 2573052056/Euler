/*************************************************************************
	> File Name: EP07-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月17日 星期二 19时09分21秒
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
#define max_n 200000

int prime[max_n + 5] = {0};

void init() {
    for (int64_t i = 2; i <= max_n; i++) {
        if (prime[i])  continue;
        prime[++prime[0]] = i;
        for (int64_t j = i * i; j <= max_n; j += i) {
            prime[j] = 1;
        } 
    }
    return ;
}

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
