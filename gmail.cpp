/*
 * =====================================================================================
 *
 *       Filename:  gmail.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月02日 18时26分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
	map<int, int>  arry;	
	int number = 0;
	srand(time(0));

	for (int i = 0;i <  10; i++ ) {
		int idx = (number > 0 ? rand() % number : 0);

		cout << (arry.find(idx) == arry.end()? idx:arry[idx]) << endl;

		--number;
		arry[idx] = (arry.find(number) == arry.end() ? number: arry[number]);
	}

	return 0;
}
