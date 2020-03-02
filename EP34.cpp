/*************************************************************************
	> File Name: EP34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月15日 星期日 20时04分38秒
 ************************************************************************/

#include<stdio.h>
#define max_n 2903040 

int keep[10] = {1, 1};
//int keep[10] = {0};

void fac () {
    /*if (keep[n]) return keep[n];
    if (n == 0) return 1;
    if (n == 1) return 1;
    return keep[n] = n * fac(n - 1);*/
    for (int i = 2; i <= 9; i++) {
        keep[i] = i * keep[i - 1];
    }
    return ;
}

int is_val(int n) {
    int x = n, tmp = 0;
    while (x) {
        tmp += keep[x % 10];   
        x /= 10;
    }
    return n == tmp;
}

int main() {
    fac();
    int sum = 0;
    for (int i = 3; i <= max_n; i++) {
        if (is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;

}
