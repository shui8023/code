/*
 * =====================================================================================
 *
 *       Filename:  shap.cpp
 *
 *    Description:  虚函数的使用
 *
 *        Version:  1.0
 *        Created:  2014年10月20日 17时58分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */


#include <iostream>
#include <math.h>

using namespace std;

class shape
{
	public:
		virtual double area() = 0;
		virtual void print_info() = 0;
};

class rectangle:public shape
{
	public:
		int w,h;
		virtual double area();
		virtual void print_info();
};

class circle:public shape
{
	public:
		int r;
		virtual double area();
		virtual void print_info();
};

class triangle:public shape
{
	public:
		int a, b, c;
		virtual double area();
		virtual void print_info();
};

double rectangle::area()
{
	return this->w * this->h;
}

void rectangle::print_info()
{
	cout << area() << endl;
}

double circle::area()
{
	return this->r * this->r;
}

void circle::print_info()
{
	cout << area() << endl;
}
double triangle::area()
{
	return this->a * this->b * this->c;
}

void triangle::print_info()
{
	cout << area() << endl;
}
int main(int argc, char *argv[])
{
	int cout;
	cin >> cout;
	shape *sh[cout];
	triangle *tr;
	circle *ci;
	rectangle *re;
	int i;

	for (i = 0; i < cout; ++i) {
		char c;
		cin >> c;
		switch(c) {
			case 'R':{
				re = new rectangle();
				cin>>re->h>>re->w;
				sh[i] = re;
				break;
			}
			case 'S':
			{
				tr = new triangle();
				cin >> tr->a >> tr->b >> tr->c;
				sh[i] = tr;
				break;
			}
			case 'D':
			{
				ci = new circle();
				cin >> ci->r;
				sh[i] = ci;
				break;
			}
		}
	}

	for (i = 0; i < cout; ++i) {
		sh[i]->print_info();
	}
	return 0;
}
