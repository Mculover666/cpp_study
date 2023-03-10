/**
 * @brief   基本输入函数cin使用示例
 * @author  Mculover666
 * @date    2023/2/26
 */

#include <iostream>

//使用方式1
//using namespace std;

//使用方式2
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int a;
    double b;
    char s[32];

	cout << "Please enter value for a:";
    cin >> a;
    cout << "a = " << a << endl;

    cout << "Please enter value for b:";
    cin >> b;
    cout << "b = " << b << endl;

    cout << "Please enter value for str:";
    cin >> s;
    cout << "s = [" << s << "]" << endl;
	
    return 0;
}

/*

运行结果：

Please enter value for a:1
a = 1
Please enter value for b:1.1
b = 1.1
Please enter value for str:hello
s = [hello]

*/
