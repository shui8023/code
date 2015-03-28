/*
 * =====================================================================================
 *
 *       Filename:  qsort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年03月21日 10时06分02秒
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
#include <string.h>

void qsort(int *data, int i, int y)
{
	if (i < y) {
		int front = i;
		int rear = y;
		int temp = data[(front+rear)/2];
		while (front < rear) {
			while (data[rear] > temp && front < rear) {
				rear--;
			}
			while (data[front] < temp && front < rear) {
				front++;
			}
			if (front < rear) {
				data[front] = data[front] + data[rear];
				data[rear] = data[front] - data[rear];
				data[front] = data[front] - data[rear];
			}
		}
	
		qsort(data, i, front - 1);
		qsort(data, front + 1, y);
	}
}

int main(int argc, char *argv[])
{
	int a[] = {1,5,3,78,213,8,0,345};

	qsort(a, 0, 7);
	int i = 0;

	for (i =0; i <= 7; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}

