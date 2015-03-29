/*
 * =====================================================================================
 *
 *       Filename:  qsort_1.cpp
 *
 *    Description:  快速排序
 *
 *        Version:  1.0
 *        Created:  2015年03月29日 11时11分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */


#include <iostream>

template<typename type>
void qsort(void *data, int front, int rear, bool (*compare)(void s1, void s2))
{
	if (front < rear) {
		int first = front;
		int end = rear;
		int temp = data[(first+end)/2];
		while (first < end) {
			while (compare(temp, data[rear])) {
				rear--;
			}
			while (compare(data[front], temp)) {
				front++;
			}

			if (first < end) {
				data[rear] = data[rear] + data[front];
				data[front] = data[rear] - data[]
			}
		}
	}
}

int main(int argv, char *argv[])
{
	return 0;
}
