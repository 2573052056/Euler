/*************************************************************************
	> File Name: EP04.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月15日 星期日 18时14分08秒
 ************************************************************************/

#include <stdio.h>

int is_val(int n, int base) {
    int x = n, tmp = 0;
    while (x) {
        tmp = tmp * base + x % base;
        x /= base;
    }
    return tmp == n;
}

int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (is_val(i * j, 10) && i * j > ans) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
