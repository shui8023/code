/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年03月20日 23时30分32秒
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

#define STACK_SIZE 20

typedef int bool;

#define true  1
#define false 0


typedef struct stack{
	int ele[STACK_SIZE];
	int top;
}my_stack;

bool init_stack(struct stack **s)
{
	*s = (struct stack *)malloc(sizeof(struct stack));

	if (NULL == *s) {
		perror("malloc");
		return  false;
	}
	(*s)->top = -1;
	printf("%p\n", *s);
	return true;
}

void delete_stack(my_stack *s)
{
	free(s);
}

bool empty_is_stack(my_stack *s)
{
	return s->top == -1 ? true:false;
}

bool full_is_stack(my_stack *s)
{
	return s->top == STACK_SIZE - 1? true:false;
}
int top(my_stack *s)
{
	if (true == empty_is_stack(s)) {
		perror("empty_stack");
	}
	return s->ele[s->top];
}
int pop(my_stack *s)
{
	if (true == empty_is_stack(s)) {
		perror("empty_stack");
	}

	return s->ele[s->top--];
}
void push(my_stack *s, int data)
{
	
	if (NULL == s ) {
		fprintf (stderr , "Pass in a null pointer " );
		return ;
	}

	(s->top)++;
	s->ele[s->top] = data;
}

int main(int argc, char *argv[])
{
	my_stack *s;
	init_stack(&s);
	push(s, 10);
	push(s, 11);
	push(s, 12);
	push(s, 13);
	push(s, 14);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	return EXIT_SUCCESS;
}
