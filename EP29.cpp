/*************************************************************************
	> File Name: EP29.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月29日 星期日 14时06分13秒
 ************************************************************************/
#include <cstring>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define max_n 10000
#define max_m 210

int result[max_n + 5][max_m];
int result_len = 0;

int find_result(int *num) {
    for (int i = 0; i < result_len; i++) {
        if (memcmp(result + i, num, sizeof(int) * max_m) == 0) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            int temp[max_m] = {1, 1, 0};
            for (int i = 0; i < b; i++) {
                for (int j = 1; j <= temp[0]; j++) temp[j] *= a;
                for (int j = 1; j <= temp[0]; j++) {
                    if (temp[j] < 10) continue;
                    temp[j + 1] += temp[j] / 10;
                    temp[j] %= 10;
                    temp[0] += (temp[0] == j);
                }
            }
            if (find_result(temp) == 0) {
                memcpy(result + result_len, temp, sizeof(int) * max_m);
                result_len += 1;
            }
        }
    }
    cout << result_len << endl;
    return 0;
}
