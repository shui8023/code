/*
 * =====================================================================================
 *
 *       Filename:  my_vector.h
 *
 *    Description:  自己实现的vector的类
 *
 *        Version:  1.0
 *        Created:  2014年10月16日 00时18分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstring>
template <typename T>
class my_vector {
	private:
		T *data;
		int len;
		int size;
	public:
		my_vector();
		my_vector(int length);
		my_vector(const my_vector &tmp);
		T &operator [](int index);
		const my_vector &push_back(const T tmp);
		int getsize();
};

my_vector::my_vector()
{
	this.data = NULL;
	this.len = 0;
	this.size = 0;
}
my_vector::my_vector(int length)
{
	data = new T[length];
	len = length;
	size = 0;
}
my_vector::my_vector(const my_vector &tmp)
{
	if (this == &tmp) {
		return ;
	}

	data = new T[tmp.len];
	for (int i = 0; i < tmp.size; ++i) {
		data[i] = tmp.data[i];
	}
	len = tmp.len;
	size = tmp.size;
}
T &operator [](int index)
{
	return data[index];
}
const my_vector &push_back(const T tmp)
{
	
}
int getsize()
{
	
}
#endif //MY_VECTOR_H
