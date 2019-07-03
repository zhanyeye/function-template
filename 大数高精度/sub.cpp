#include <iostream>
#include <cstring>

using namespace std;

void sub(char a[], char b[], char t[]) {
    int alen = strlen(a);
    int blen = strlen(b);
    t[alen] = '\0';
    int i, j;

    //计算低blen位相减的结果，并存入t[]
    for (i = alen - 1, j = blen - 1; j >= 0; i--, j--) {
        if (a[i] - b[j] >= 0) {
            t[i] = a[i] - b[j] + '0';
        } else { //被减数的该位不够时，向前一位借位
            t[i] = 10 + a[i] - b[j] + '0';
            a[i-1]--;
        }
    }

    //向前扫描，若位数小于0，向前一位借位，并存入t[]，位数大于0时停止扫描
    while (a[i] < '0' && i >= 0) {
        t[i] = a[i] + 10;
        a[--i]--;
    }

    //将剩余的高位存入t[]
    while (i >= 0) { 
        t[i] = a[i];
        i--;
    }

    //去除前导0
    int cnt = 0;
    while (t[cnt] == '0' && cnt != alen -1) {
        cnt++;
    }
    strcpy(t, t + cnt);
}

int main() {
    char a[100], b[100], ans[100];
    cin >> a >> b;
    sub(a, b, ans);
    cout << ans << endl;
    return 0;
}