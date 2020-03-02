/*************************************************************************
	> File Name: test1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月17日 星期二 20时02分56秒
 ************************************************************************/
#include <stdio.h>
#define max_n 1000

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i < max_n; i++) {
        if (prime[i])  continue;
        for (int j = i; j <= max_n; j += i) {
            if(prime[j]) continue;
            prime[j] = i;        
        }
    }
    return ;
}

int main() {
    init();
    int n;
    while(~scanf("%d", &n)) {
        printf("min_factor(%d) = %d\n", n, prime[n]);   
    }
    return 0;
}
