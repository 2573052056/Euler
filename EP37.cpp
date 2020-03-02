/*************************************************************************
	> File Name: EP37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月22日 星期日 20时00分06秒
 ************************************************************************/
#include<iostream>
using namespace std;
#include <cmath>
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {1, 1, 0};

void init() {
    for (int i = 2; i < max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_val1(int n) {
    int digit = floor(log10(n)) + 1;
    int h = (int)pow(10, digit - 1);
    int tmp = n;
    for (int i = digit; i > 0; i--) {
        tmp %= 10;
        //tmp = (tmp % 10) * h + tmp / 10;
        if (is_prime[tmp]) return 0;
    }
    return 1;
}

int is_val2(int n) {
    int digit = floor(log10(n)) + 1;
    int h = (int)pow(10, digit - 1);
    int tmp = n;
    for (int i = digit; i > 0; i--) {
        tmp /= 10;
        if (is_prime[tmp]) return 0;
    }
    return 1;
}

int main() {
    init();
    int sum = 0;
    for (int i = 11; i <= prime[0]; i++) {
        if (!is_val1(prime[i]) && !is_val2(prime[i])) continue;
        sum += prime[i];
    }
    cout << sum << endl;
    return 0;
}
