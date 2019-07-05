#include <iostream>

using namespace std;

//任意2种进制之间转换
void conversion(char s[], char ans[], int d1, int d2) {
    int sum = 0;
    int t;
    //先转换为10进制 (因为乘除运算都是在10进制下的)
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] <= '9' && s[i] >= 0) {
            t = s[i] - '0';
        } else {
            t = s[i] - 'A' + 10;
        }
        sum = sum * d1 + t; 
    }

    //将10 进制准换成 ?进制
    int i = 0;
    while (sum != 0) {
        t = sum % d2;
        if (t < 9) {
            ans[i] = t + '0';
        } else {
            ans[i] = t - 10 + 'A';
        }
        sum /= d2;
        i++;
    }

    //倒置字符串
     i--;
     int tmp;
     for (int j = 0; j <= i/2; j++) {
         tmp = ans[j];
         ans[j] = ans[i-j];
         ans[i-j] = tmp;
     }
     ans[i+1] = '\0';
}

int main() {
    char a[100], b[100];
    int m, n;
    cin >> m >> n;
    cin >> a;
    conversion(a, b, m, n);
    cout << b << endl;
    return 0;
}