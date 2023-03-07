/**
 * @brief   指针和引用的区别
 * @author  Mculover666
 * @date    2023/3/6
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 10;     //普通变量

    int b = a;      //定义一个新的普通变量，把a的值给它
    int *c = &a;    //定义一个新的指针变量，把a的地址作为它的值，它自己本身也是一个变量，有新的地址
    int &d = a;     //定义一个新的引用变量，仅仅是a的别名，地址和值都和a是一样的


    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << ", *c = " << *c << endl;
    cout << "d = " << d << endl;

    cout << "a address = " << &a << endl;
    cout << "b address = " << &b << endl;
    cout << "c address = " << &c << endl;
    cout << "d address = " << &d << endl;

    return 0;
}

/**

运行结果：

a = 10
b = 10
c = 0x7ffde8315860, *c = 10
d = 10
a address = 0x7ffde8315860
b address = 0x7ffde8315864
c address = 0x7ffde8315868
d address = 0x7ffde8315860

结论：

1. 
    - 定义一个新的指针变量：该新指针变量的本质还是变量，有自己的地址，把某个变量的地址作为指针的值，称之为指向某个变量
    - 定义一个新的引用变量：仅仅是一个新的变量名，地址和值都是原来变量的
2.
    - 指针变量可以先定义，再赋值，并且可以随时修改值
    - 引用变量在定义的时候必须赋值，而且定义后无法修改值
*/