/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description: 基于list.h的链表的实现
 *
 *        Version:  1.0
 *        Created:  2014年04月18日 00时12分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct student_message{
	char *name;
	long number;
	char *collage;
	char sex;
	int year;
	struct list head;
}st_mes;

/*使用链表
 *
 *
 */
int list_use()
int main(int argc, char *argv[])
{
	st_mes  student;
	
	student = (st_mes *)malloc(sizeof(st_mes));
	student.name = (char *)malloc(6);
	student.collage = (char *)malloc(10);

	return EXIT_SUCCESS;
}

