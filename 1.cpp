/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  用分治法实现最大值最小的值的查找
 *
 *        Version:  1.0
 *        Created:  2014年06月02日 23时58分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define MAX_COUNT 20

class big_small
{
	private:
		vector<int> number;
		int big, small;
	public:
	big_small(const int *num, const int count);
	void min_max(const int start, const int end);
	void print();
};
void big_small::print()
{
	cout << big << endl;
	cout << small << endl;
}

big_small::big_small(const int *num, const int count)
{
	for (int i = 0; i < count; ++i){
		number.push_back(num[i]);
	}
//	small = (1 << 31) -1 ;
	small = pow(2, 31) - 1;
	big = 1<<31;
}

void big_small::min_max(const int start, const int end)
{
	vector<int> tmp;
	if ((end - start) <= 1) {
		if (number[end] > number[start]) {
			if (number[end] > big){
				big = number[end];
			}
			if (number[start] < small) {
				small = number[start];
			}
		} else {
			if (number[start] > big){
				big = number[start];
			}
			if (number[end] < small) {
				small = number[end];
			}
		}
		
		return;
	}

	min_max(start, (start+end)/2);
	min_max((start+end)/2 + 1, end);

}

int main(int argc, char *argv[])
{
	int tmp[MAX_COUNT];
	srand(time(NULL));

	for (int i = 0; i < MAX_COUNT; ++i){
		tmp[i] = rand()%100 + 1;
		cout << tmp[i] << "\t";
	}
	cout << endl;
	big_small p(tmp, MAX_COUNT);

	p.min_max(0, MAX_COUNT - 1);
	p.print();

	return 0;
}
