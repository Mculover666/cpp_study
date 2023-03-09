/**
 * @brief   
            1. 引用变量的典型用途：按引用传递
            2. 按值传递、按指针传递、按引用传递的区别
 * @author  Mculover666
 * @date    2023/3/7
*/

#include <iostream>
using namespace std;

void swapv(int a, int b);
void swapp(int *a, int *b);
void swapr(int &a, int &b);

int main(void)
{
    int a = 10;
    int b = 20;

    /* 按值传递 */
    cout << "before: a = " << a << ", b = " << b << endl;
    swapv(a, b);
    cout << "after:  a = " << a << ", b = " << b << endl;

    /* 按指针传递 */
    cout << "before: a = " << a << ", b = " << b << endl;
    swapp(&a, &b);
    cout << "after:  a = " << a << ", b = " << b << endl;

    /* 按引用传递 */
    cout << "before: a = " << a << ", b = " << b << endl;
    swapr(a, b);
    cout << "after:  a = " << a << ", b = " << b << endl;

    return 0;
}

/** 
 * @brief   按值传递
 * @note    创建新的变量a和b，只传入值进去，所以交换无效
 */
void swapv(int a, int b)
{
    int t;

    t = a;
    a = b;
    b = t;
}

/** 
 * @brief   按指针传递
 * @note    创建新的指针变量a和b，传入地址进去，指针实际指向的是原来的变量，所以交换有效
 */
void swapp(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

/** 
 * @brief   按引用传递
 * @note    创建新的引用变量a和b，只是传入参数的别名，所以实际操作的还是原来的变量，交换有效
 */
void swapr(int &a, int &b)
{
    int t;

    t = a;
    a = b;
    b = t;
}

/**

运行结果：

before: a = 10, b = 20
after:  a = 10, b = 20
before: a = 10, b = 20
after:  a = 20, b = 10
before: a = 20, b = 10
after:  a = 10, b = 20

总结：

1. 按引用传递和按值传递，唯一的外在区别是声明函数参数的方式不同，内在区别是传递引用会操作原始数据，而传递值只是值的拷贝
2. 按引用传递和按指针传递，第一个区别是声明函数参数不同，第二个不同是指针在操作过程中需要解引用运算符*

*/