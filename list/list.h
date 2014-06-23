/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  list.h的简单使用
 *
 *        Version:  1.0
 *        Created:  2014年06月23日 14时33分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#ifndef LIST_H
#define LIST_h

typedef 
struct list_head {
	list_head *next;
	list_head *prev;
}list_head;

#define LIST_HEAD(head) 	\
	head = {&head, &head}
#define LIST_HEAD_INIT(name) 	\
	struct list_head name = LIST_HEAD

#endif //LIST_H

