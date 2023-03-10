/**
 * @brief   演示如何定义函数的默认参数
 * @author  Mculover666
 * @date    2023/3/10
*/

#include <iostream>
using namespace std;

int add(int a, int b = 1);

int main()
{
    cout << "two para result:" << add(2, 2) << endl;
    cout << "one para result:" << add(2) << endl;

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

/*

运行结果：

two para result:4
one para result:3

*/