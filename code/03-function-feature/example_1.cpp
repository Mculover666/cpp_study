/**
 * @brief   演示如何定义内联函数
 * @author  Mculover666
 * @date    2023/3/10
*/

#include <iostream>
using namespace std;

/**
 * @brief   计算平方
 * @note    内联函数
*/
inline double square(double x) { return x * x; }

int main()
{
    double a = 2.2;

    cout << "result is: " << square(a) << endl;

    return 0;
}

/*

运行结果：

result is: 4.84

总结：

1. 内联函数定义和声明时需要添加关键字inline，其余和普通函数一样
2. 在本质上，内联函数会由编译器替换调用处的代码，而普通函数则是函数调用逻辑

*/