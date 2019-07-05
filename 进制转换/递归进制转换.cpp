#include <iostream>
#include <vector>
using namespace std;

//10进制转换为其他进制(小于10进制)
void trans1(int m, int k) {
    int r = m % k;
    if (m >= k) {
        m /= k;
        trans1(m, k); 
    }    
    cout << r; //直接输出结果
}


//将值存在vector中
vector<int> v;
void trans2(int m, int k) {
    int r = m % k;
    if (m >= k) {
        m /= k;
        trans2(m, k);
    }
    v.push_back(r);
}

int main() {
    int m, k;
    cin >> m >> k;
    trans1(m, k);
    cout << endl << "----------" << endl;
    trans2(m, k);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    return 0;
}
