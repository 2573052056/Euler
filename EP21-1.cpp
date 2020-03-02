/*************************************************************************
	> File Name: EP21-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月29日 星期日 18时30分57秒
 ************************************************************************/

#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define max_n 4000000

int f[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j) continue;
            f[i] += j;
            f[i] += i / j;
        }
        f[i] -= i;
    } 
    return ;
}

void init1() {
    for (int i = 1; i <= max_n; i++) {
        for (int j = 2; i * j <= max_n; j++) {
            f[i * j] += i;
        }
    } 
    return ;
}

int main() {
    //init();
    init1();
    long long sum = 0;
    for (int i = 2; i < max_n; i++) {
        if (f[i] != i && f[i] < max_n && i == f[f[i]])  sum += i;
    }
    cout << sum << endl;
    return 0;
}

