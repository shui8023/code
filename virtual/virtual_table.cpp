/*
 * =====================================================================================
 *
 *       Filename:  virtual_table.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月20日 22时16分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */


#include <iostream>

using namespace std;

class test1
{
	public:
		int value;
		virtual void print() = 0;
		virtual void print1() = 0;
		virtual void print2() = 0;
		virtual void print3() = 0;
		virtual void print4() = 0;
		virtual void print5() = 0;
};
class test2:public test1
{
	public:
		double value;
		virtual void print() = 0;
};
/*编译器会在类中放置一个指向虚函数表的指针，在32位机器中是4个字节
 *动态联编，在运行时判断调用那个虚函数，
 */
int main(int argc, char *argv[])
{
	cout << sizeof(test1) << "and" << sizeof(test2) << endl;

	return 0;
}
