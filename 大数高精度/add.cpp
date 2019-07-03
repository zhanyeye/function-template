#include <iostream>
#include <cstring>

using namespace std;



void add(char a[], char b[], char ans[]) {
    int alen = strlen(a);
    int blen = strlen(b);
    int len = (alen > blen ? alen : blen) + 2; //+2 一个留给进位，一个留给'\0'
    char *c = new char[len]; //用来存结果（逆序）

    int k = 0;   //ans的操作索引
    int up = 0;  //进位

    //2个索引分别指向字符串的最后一位,只要其中一个索引大于等于0，就向前遍历
    for (int i = alen - 1, j = blen - 1; i >= 0 || j >= 0; i--, j--) {
        int x = (i >= 0 ? a[i] - '0' : 0);
        int y = (j >= 0 ? b[j] - '0' : 0);
        int z = x + y + up;
        if (z > 9) {
            up = 1;
            z %= 10;
        } else {
            up = 0;
        }
        c[k++] = z + '0'; //还原成数字，妙啊！！
    }
    if (up > 0) { //如果最高位有进位
        c[k++] = '1';
    }

    //倒置字符串
    int cnt;
    for (cnt = 0; cnt < k; cnt++) {
        ans[cnt] = c[k - cnt - 1];
    }
    ans[cnt] = '\0'; //加上结束符
}


int main() {
    char a[100];
    char b[100];
    char c[100];
    scanf("%s%s", a, b);
    add(a, b, c);
    printf("%s",c);
    return 0;
}