/*************************************************************************
	> File Name: EP47.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月29日 星期日 18时06分25秒
 ************************************************************************/

#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i]) continue;
        for (int j = i ; j <= max_n; j += i) {
            prime[j] += 1;
        }
    }
    return ;
}

int main() {
    init();
    int ans = 0;
    for (int i = 1000; i < max_n; i++) {
        int flag = 1;
        for (int j = 0; j < 4 && flag; j++) {
            flag = (prime[i + j] == 4);
        }
        if (!flag) continue;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}
