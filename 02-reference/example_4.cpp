/**
 * @brief   传递引用的典型场景：将引用用于结构体传递
 * @author  Mculover666
 * @date    2023/3/7
*/

#include <iostream>
using namespace std;

struct free_throws
{
    string name;
    int made;
    int attempts;
    float percent;
};

/**
 * @brief   打印所有成员的值
 * @param   ft  const类型的引用变量，防止ft被修改
 * @return  none
*/
void display(const free_throws &ft);

/**
 * @brief   设置百分比成员的值
 * @param   ft  需要修改结构体中成员的值，所以传递引用
 * @return  none
*/
void set_pc(free_throws &ft);

/**
 * @brief   积累
 * @param   target  修改成员值，传递引用
 * @param   source  只是使用值，const类型的引用变量，防止ft被修改
 * @return  返回引用，添加const修饰，防止返回的引用被直接赋值修改
*/
const free_throws &accumulate(free_throws &target, const free_throws &source);

int main(void)
{
    /* 指定的初始化值比成员少，余下的成员会被初始化为0 */
    free_throws one = {"A", 13, 14};
    free_throws two = {"B", 10, 16};
    free_throws three = {"C", 7, 9};
    free_throws four = {"D", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};

    /* 未初始化，其中的成员是随机值 */
    free_throws dup;
    display(dup);

    set_pc(one);
    display(one);
    accumulate(team, one);

    //使用返回的引用变量作为参数
    display(accumulate(team, two));
    accumulate(team, three);
    accumulate(team, four);
    display(team);

    //在C++中，结构体之间可以互相赋值
    dup = one;
    display(dup);

    //使用返回的引用值
    dup = accumulate(team, five);
    display(team);
    display(dup);
    
    set_pc(four);
    //因为函数返回的是一个引用，所以可以将值赋给函数调用
    //这一句实际逻辑是有问题的，首先传入dup，将five的值累加到dup后，返回dup，随后又将four的值赋给dup，最终dup中的值是four的值
    //该问题可以通过返回const类型的引用来解决
    //添加const修饰后，该语句不合法
    //accumulate(dup, five) = four;   
    accumulate(dup, five);
    display(dup);

    return 0;
}

void display(const free_throws &ft)
{
    cout << "Name: " << ft.name << '\n';
    cout << "  Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws &ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made)/float(ft.attempts);
    else
        ft.percent = 0;
}

const free_throws &accumulate(free_throws &target, const free_throws &source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);

    /*
        按引用传递的好处：
    
        按值传递的时候，需要将值拷贝到一个临时位置，再拷贝给外部变量；
        按引用传递的时候，可以直接将值拷贝给外部变量，效率更高
    */
    return target;
}

/**

运行结果：

Name: 
  Made: -2011063488     Attempts: 32642 Percent: 0
Name: A
  Made: 13      Attempts: 14    Percent: 92.8571
Name: Throwgoods
  Made: 23      Attempts: 30    Percent: 76.6667
Name: Throwgoods
  Made: 35      Attempts: 48    Percent: 72.9167
Name: A
  Made: 13      Attempts: 14    Percent: 92.8571
Name: Throwgoods
  Made: 41      Attempts: 62    Percent: 66.129
Name: Throwgoods
  Made: 41      Attempts: 62    Percent: 66.129
Name: D
  Made: 5       Attempts: 9     Percent: 55.5556

总结：

1. 在C++中，传递结构体或者对象的时候，都使用的是引用传递，相比传递原始数据的拷贝（传递值）来说，节省内存和时间
2. 在C++中，未初始化的变量是随机值，不会自动初始化
3. 如果引用变量仅仅是使用值，一般设为const类型防止修改
4. 在C++中，结构体之间可以互相赋值
5. 返回引用的好处是效率更高，应该避免返回函数终止时不存在的内存，一般做法是返回一个作为参数传递给函数的引用

*/