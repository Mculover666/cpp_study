/**
 * @brief   c++版本helloworld示例
 * @author  Mculover666
 * @date    2023/2/26
 */

#include <iostream>
using namespace std;

int main()
{
    int  a = 1;
    double b = 3.14;
    char c[] = "str test";

    bool flag = false;

	cout << "Hello World!" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = [" << c << "]" << endl;

    if (flag)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
	
    return 0;
}
