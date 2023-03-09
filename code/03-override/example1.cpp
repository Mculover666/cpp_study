/**
 * @brief   演示如何定义函数重载
 * @author  Mculover666
 * @date    2023/3/9
*/
#include <iostream>
using namespace std;

/* 四个函数重载 */
int add(int a, int b);
double add(double a, double b);
double add(int a, double b);
double add(double a, int b);

int main(void)
{
    cout << add(1, 1) << endl;
    cout << add(1.1, 1.1) << endl;
    cout << add(1, 1.1) << endl;
    cout << add(1.1, 1) << endl;

    return 0;
}

int add(int a, int b)
{
    cout << "#1 add called!" << endl;
    return a + b;
}

double add(double a, double b)
{
    cout << "#2 add called!" << endl;
    return a + b;
}

double add(int a, double b)
{
    cout << "#3 add called!" << endl;
    return a + b;
}

double add(double a, int b)
{
    cout << "#4 add called!" << endl;
    return a + b;
}

/*

运行结果：

#1 add called!
2
#2 add called!
2.2
#3 add called!
2.1
#4 add called!
2.1

总结：

1. 函数重载：函数名相同，特征标不同。
    特征标是指函数的参数列表（参数数量或参数类型），和返回值无关。
2. 函数重载创建和使用时，要注意数据类型的隐式转换。
3. 何时使用函数重载：仅当函数基本上执行相同的任务，但使用不同形式的数据时，才应使用函数重载。

*/
