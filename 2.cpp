/*
 * =====================================================================================
 *
 *       Filename:  2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月28日 12时45分28秒
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

using namespace std;

class sort{
	private:
		vector<int> number;
	public:
		sort(const vector<int> p);
		sort_number(const int begin, const int end);
		merg_number(const int begin, const int end);
		sort_print();
};

sort::sort(const vector<int> p)
{
	number = p;
}
void sort::sort_number(const int begin, const int end)
{
	if ((end - begin) < 1) {
		if (number[begin] < number[end]){
			int tmp = number[begin];
			number[begin] = number[end];
			number[end] = tmp;
		}

	}
	sort_number(begin, (begin + end) / 2);
	sort_number((begin + end) / 2 + 1, end);
	merg_number(begin, end);

}
void sort::merg_number(const int begin, const int end)
{
	int tmp = (begin + end) / 2;

	for (int i = 0, int j = tmp + 1; i < tmp && j < end ; ++i, ++j) {
		if 
	}

}
