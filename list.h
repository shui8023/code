/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年04月16日 23时15分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#ifndef LIST_H
#define LIST_H


/*@define filed list
 *
 */
struct list{
	struct list *next;
	struct list *priv;
};

/*@statment list
 *@the point to themself
 *
 */
#define LIST_HEAD_INIT(name) 	\
		{&(name), &(name)}

#define LIST_INIT(name)  	\
		struct list name = LIST_HEAD_INIT(name)

/*@establishment of the list
 *@
 *
 */
void list_built(struct list *new, struct list *next, struct list *priv)
{
	new->next = next;
	next->priv = new;
	new->priv = priv;
	priv->next = new;
}

void list_bulit_head(struct list *new, struct list *head)
{
	list_built(new, head, head->next);
}


void list_bulit_tail(struct list *new, struct list *head)
{
	list_built(new, head->priv, head);
}


/*@linked list traversal
 *
 *
 */
#define 		

#endif
