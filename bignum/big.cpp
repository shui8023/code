/*
 * =====================================================================================
 *
 *       Filename:  big.cpp
 *
 *    Description:  大数计算的实现
 *
 *        Version:  1.0
 *        Created:  2014年10月23日 17时21分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#include <iostream>
#include <assert.h>
#include <string>
#include <cstring>
const int max_count = 300;

using namespace std;

class big_num{
private:
	int data[max_count];
	int length;
	bool sign;
public:
	big_num();
	big_num operator+(const big_num &p)const;
	big_num operator-(const big_num &p)const;
	big_num operator*(const big_num &p)const;
	big_num operator/(const big_num &p)const;
	int &operator[](int index);
	int operator[](int index) const;
	bool operator<(const big_num &p)const;
	big_num operator<<(int count) const;
	big_num operator*(int number)const;
	void init_big_num();
	void print();
};
big_num::big_num()
{
	memset(data, 0, sizeof(data));
	length = 0;
	sign = true;
}
big_num big_num::operator<<(int count)const
{
	int tmp;
	big_num c;
	
	for (int i = 0; i < length; ++i) {
		c[i + count] = data[i];
	}
	//debug
	c.length += length + count;

	return c;
}
int &big_num::operator[](int index)
{
	assert(index >= 0 && index < max_count);

	return data[index];
}

int big_num::operator[](int index) const
{
	assert(index >= 0 && index < max_count);

	return data[index];
}

big_num big_num::operator+(const big_num &p)const
{
	big_num c;
	int tmp = 0;

	for (int i = 0; i < length || i < p.length || tmp; ++i) {
		int s = data[i] + p[i] + tmp;
		c[i] = s % 10;
		tmp = s / 10;
		c.length++;
	}

	return c;
}

bool big_num::operator<(const big_num &p) const
{
	if (this->length != p.length) {
		return length < p.length;
	}

	for (int i = length - 1; i >= 0; --i) {
		if (data[i] != p.data[i]) {
			return data[i] < p.data[i];
		}
	}

	return false;
}


big_num big_num::operator-(const big_num &p) const
{
	if (*this < p) {
		big_num c = p - *this;
		c.sign = false;
		return c;
	}
	big_num c;
	int tmp = 0;

	for (int i = 0; i < length; ++i) {
		int s = data[i] - p[i] - tmp;
		if (s < 0) {
			s += 10;
			tmp = 1;
		} else {
			tmp = 0;
		}
		c[i] = s;
		c.length++;
	}

	while (c.length > 1 && c[length - 1] == 0) {
		c.length--;
	}

	return c;
}

big_num big_num::operator*(int number)const
{
	int t = 0;
	big_num c;
	
	for (int i = 0; i < length || t; ++i) {
		int s = data[i] * number + t;
		t = s / 10;
		c[i] = s % 10;
		c.length++;
	}

	return c;
}

big_num big_num::operator*(const big_num &p)const
{
	big_num c;

	for (int i = 0; i < p.length; ++i) {
		c = c + (((*this) * p.data[i]) << i);
	}

	return c;
}

void big_num::init_big_num()
{
	string str;
	
	cin >> str;

	length = str.size();
	
	for (int i = 0; i < length; ++i) {
		data[length - i - 1] = str[i] - '0';
	}
	
}

void big_num::print()
{
	if (!sign) {
		cout << '-';
	}

	for (int i = 0; i < length; ++i) {
		cout << data[length - i - 1];
	}

	cout << endl;
}

int main(int argc, char *argv[])
{
	big_num a, b, c;
	char p;

	a.init_big_num();
	cin >>p;
	b.init_big_num();
	
	if (p == '+') {
		c = a + b;
	}

	if (p == '-') {
		c = a - b;
	}
	
	if (p == '*') {
		c = a * b;
	}

	c.print();
}
