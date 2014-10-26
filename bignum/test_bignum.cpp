/*
 * =====================================================================================
 *
 *       Filename:  test_bignum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月26日 18时40分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignum.h"

int main(int argc, char *argv[])
{
	big_num a, b , c;
	char p;

	while (cin >> a >> p >> b) {
		if (p == '+') {
			c = a + b;
		}
		if (p == '-') {
			c = a - b;
		}
		if (p == '*') {
			c = a * b;
		}
		if (p == '/') {
			c = a + b;
		}

		cout << c;
	}

	return EXIT_SUCCESS;
}

