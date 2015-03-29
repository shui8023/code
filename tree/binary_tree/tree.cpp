/*
 * =====================================================================================
 *
 *       Filename:  tree.c
 *
 *    Description:  二叉树的基本操作
 *
 *        Version:  1.0
 *        Created:  2015年03月27日 20时01分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
struct tree{
	char data;
	struct tree *left;
	struct tree *right;
};

//先序建立二叉树ABD^G^^^CE^H^^F^^
void init_tree(struct tree **root)
{
	char c;
	c = fgetc(stdin);

	if (c == '^') {
		*root = NULL;
	} else {
		*root = (struct tree *)malloc(sizeof(struct tree));
		(*root)->data = c;
		init_tree(&((*root)->left));
		init_tree(&((*root)->right));
	}
	
}

//先序遍历二叉树
void pre_tree(struct tree *root)
{
	if (root != NULL) {
		printf("%c\t", root->data);
		pre_tree((root->left));
		pre_tree((root->right));
	}
}

//中序遍历
void mid_tree(struct tree *root)
{
	if (root != NULL) {
		mid_tree((root->left));
		printf("%c\t", root->data);
		mid_tree((root->right));
	}
}

//后序遍历
void front_tree(struct tree *root)
{
	if (root != NULL) {
		front_tree((root->left));
		front_tree((root->right));
		printf("%c\t", root->data);
	}
}

//先序非递归
void pre_tree_list(struct tree *root)
{
	std::stack<tree *> st;
	struct tree *p = root;
	while (p != NULL || !st.empty()) {
		while (p != NULL) {
			std::cout << p->data << "\t";
			st.push(p);
			p = p->left;
		}
		if (!st.empty()) {
			p = st.top();
			st.pop();
			p = p->right;
		
		}
	}
}
//中序非递归
void mid_tree_list(tree *root)
{
	std::stack<tree *> st;
	struct tree *p = root;
	while (p != NULL || !st.empty()) {
		while (p != NULL) {
			st.push(p);
			p = p->left;
		}
		if (!st.empty()) {
			std::cout << st.top()->data << "\t";
			p = st.top();
			p = p->right;
			st.pop();
		}
	}
}

//后序非递归
void front_tree_list(tree *root)
{
	std::stack<tree *> st;
	struct tree *p = root, *q = NULL;

	while (p != NULL || !st.empty()) {
		while (p != NULL) {
			st.push(p);
			p = p->left;
		}

		if (!st.empty()) {
			p = st.top();
			if (p->right == NULL || p->right == q) {
				st.pop();
				std::cout << p->data << "\t";
				q = p;
				p = NULL;
			} else {
				p = p->right;
			}
		}
	}
}

//层次遍历
void level_order(tree *root)
{
	std::queue<tree *> qu;
	tree *p = root;
	qu.push(p);

	while (!qu.empty()) {
		p = qu.front();
		qu.pop();
		std::cout << p->data<<"\t";
		if (p->left != NULL) {
			qu.push(p->left);
		}
		if (p->right != NULL) {
			qu.push(p->right);
		}
	}
}

//求二叉树的高度
int height_tree(struct tree *root)
{
	if (root == NULL) {
		return 1;
	} else {
		int h1 = height_tree(root->left);
		int h2 = height_tree(root->right);
		return (h1 < h2)? h2 + 1 : h1 + 1;
	}
}

//求二叉树的节点的个数

int main(int argc, char *argv[])
{
	struct tree *root;
	init_tree(&root);
	printf("\n");
	pre_tree(root);
	printf("\n");
	pre_tree_list(root);
	printf("\n");
	mid_tree(root);
	printf("\n");
	mid_tree_list(root);
	printf("\n");
	front_tree(root);
	printf("\n");
	front_tree_list(root);
	printf("\n");
	level_order(root);
	printf("\n");
	std::cout << height_tree(root) << std::endl;
	return 0;
}
