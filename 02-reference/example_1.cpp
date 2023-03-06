#include <iostream>
using namespace std;

int main(void)
{
    int a = 10;

    //创建一个引用，给a起个别名，叫b
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //修改b的值
    b = 200;

    //再次查看a和b的值
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
