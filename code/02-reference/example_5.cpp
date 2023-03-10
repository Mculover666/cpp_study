/**
 * @brief   演示返回不存在内存的危害
 * @author  Mculover666
 * @date    2023/3/10
*/

#include <iostream>
using namespace std;

int & test(void)
{
    int t = 22;
    int &ref = t;
    cout << "ref = " << ref << endl;
    return ref;
}

int main(void)
{
    int &a = test();
    cout << "a = " << a << endl;
    cout << "a = " << a << endl;
    return 0;
}

/**

运行结果：

ref = 22
a = 32620
a = 32620

总结：

1. 返回引用时要避免返回内存已不存在的值。

*/