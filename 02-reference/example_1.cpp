/**
 * @brief   演示如何定义引用变量
 * @author  Mculover666
 * @date    2023/3/6
*/

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

    //查看a和b的地址
    cout << "a address = " << &a << endl;
    cout << "b address = " << &b << endl;

    return 0;
}

/**

运行结果：

a = 10
b = 10
a = 200
b = 200
a address = 0x7ffd8805288c
b address = 0x7ffd8805288c

总结：

1. 引用就是给变量创建一个别名，地址和值都相同

*/