/*
 * =====================================================================================
 *
 *       Filename:  bignum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月21日 16时07分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#define MAX_NUM 200

using namespace std;

class bignum
{
private:
	int data[MAX_NUM];
	int length;
	int sign;
public:
	bignum();
	bignum(int a[], int length);
	void read_int(string str);
	void print();
	bignum operator +(bignum p);
	bignum operator -(bignum p);
//	bignum operator *(bignum p);
//	bignum operator /(bignum p);
};
void bignum::read_int(string str)
{
	int count = str.size();
	int i = 0;
	sign = 0; //0是正数
	
	if (str[0] == '-') {
		sign = -1;
	}
	
	for (i = 0; i < count - 1; ++i) {
		this->data[i] = str[i] - '0';
	}

	reverse(data, data+count);
	length = count;
	if (sign == -1) {
		length = length - 1;	
	}

}
bignum::bignum()
{
	memset(data, 0, MAX_NUM);
	length = 0;
	sign = 0;
}

bignum::bignum(int a[], int len)
{
	int i = 0;
	memset(data, 0, MAX_NUM);
	
	for (i = 0; i < len; ++i) {
		data[i] = a[i];			
	}

	length = len;
}
void bignum::print()
{
	int i;
	for (i = length - 1; i >= 0; --i) {
		cout << data[i];
	}
	cout << endl;
}
istream &operator >>(istream &in, bignum big)
{
	string str;
	in >> str;
	big.read_int(str);
	return in;
}

ostream &operator <<(ostream &os, bignum big)
{
	big.print();
	return os;
}
bignum bignum::operator+(bignum p)
{
	int tmp = 0;
	int i = 0; 

	for (i = 0; i < length || i < p.length; ++i) {
		data[i] = p.data[i] + data[i] + tmp;
		tmp = data[i] / 10;
		data[i] = data[i] % 10;
		
	}
	if (tmp > 0) {
		data[i] = tmp;
	}
	
	length = i;
	
	return *this;
}

bignum bignum::operator -(bignum p)
{
	if (length > p.length) {
		
	}
}
#ifdef DEBUG
int main(int argc, char *argv[])
{
	string str1, str2;
	
	cin >> str1 >> str2;
	
	int num_count1 = str1.size();
	int num_count2 = str2.size();

	int num1[MAX_NUM];
	int num2[MAX_NUM];
	
	//解决负数的问题
	for (int i = 0; i < num_count1; ++i) {
		num1[i] = str1[num_count1 - 1 - i] - '0';
	}
	
	for (int i = 0; i < num_count2; ++i) {
		num2[i] = str2[num_count2 - 1 - i] - '0';
	}
	
	bignum big_num1(num1, num_count1);
	bignum big_num2(num2, num_count2);

	big_num1.print();
	big_num2.print();
	bignum big_num3;
//	big_num3 = big_num1.operator+(&big_num2);
	big_num3 = big_num1 + big_num2;
	big_num3.print();
}

#endif 
#ifdef BUG
int main(int argc, char *argv[])
{
	bignum num1, num2, num3;

	cin >> num1 >> num2;
	num3 = num1 + num2;
	cout << num3;
	return 0;
}

#endif
