/**
 * @brief   基本输出函数cout使用示例
 * @author  Mculover666
 * @date    2023/2/26
 */

#include <iostream>

//使用方式1
//using namespace std;

//使用方式2
using std::cout;
using std::endl;


int main()
{
    int  a = 1;
    double b = 3.14;
    char c[] = "str test";

	cout << "Hello World!" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = [" << c << "]" << endl;
	
    return 0;
}

/*

运行结果：

Hello World!
a = 1
b = 3.14
c = [str test]

*/
