/**
 * @brief   演示使用const修饰符进行重载的区别
 * @author  Mculover666
 * @date    2023/3/9
*/
#include <iostream>
using namespace std;

/* 函数重载 */
void dribble(char *bits);
void dribble(const char *cbits);

/* 普通函数，未重载 */
void dabble(char * bits);

/* 普通函数，未重载 */
void drivel(const char *cbits);

int main(void)
{
    const char p1[] = "str1";
    char p2[] = "str2";

    /*
        已经定义函数重载，所以编译器根据参数是否被const修饰来判断调用哪个函数
    */
    dribble(p1);
    dribble(p2);

    /*
        该语句语法错误，不可将const修饰的变量传给普通变量。
        error: invalid conversion from ‘const char*’ to ‘char*’ [-fpermissive]
    */
    //dabble(p1);
    dabble(p2);

    /*
        语法正确，函数参数使用const修饰
        未定义函数重载，所以如果传入非const修饰的，编译器会对参数隐式转换，并不存在函数重载的机制
    */
    drivel(p1);
    drivel(p2);

    return 0;
}

void dribble(char *bits)
{
    cout << "#1 dribble called!" << endl;
    cout << bits << endl;
}

void dribble(const char *cbits)
{
    cout << "#2 dribble called!" << endl;
    cout << cbits << endl;
}

void dabble(char * bits)
{
    cout << "dabble called!" << endl;
    cout << bits << endl;
}

void drivel(const char *cbits)
{
    cout << "drivel called!" << endl;
    cout << cbits << endl;
}

/*

运行结果：

#2 dribble called!
str1
#1 dribble called!
str2
dabble called!
str2
drivel called!
str1
drivel called!
str2

总结：

1. 如果函数存在重载，则优先按照已有的重载类型进行匹配调用，失败再进行数据隐式转换进行匹配。
2. 如果函数未定义重载，则按照数据隐式转换进行匹配调用。

*/
