/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.cpp
 *
 *    Description:  二叉树的基本操作
 *
 *        Version:  1.0
 *        Created:  2015年03月26日 22时54分42秒
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


template<typename type>
class binary_tree{
public:
	binary_tree()
	{
		root = NULL;	
	}
	binary_tree(const binary_tree &rhs)
	{
		make_empty(root);
		root = clone(rhs.root);
	}
	const binary_tree & operator= (const binary_tree &rhs)
	{
		if (*this != rhs) {
			make_empty(root);
			root = clone(rhs.root);
		}

		return *this;
	}
	~binary_tree()
	{
		make_empty(root);
	}

	bool isempty() const
	{
		if (root != NULL) {
			return false;
		}
		return true;
	}
	void printtree(int i = 0) const;
	void insert(const type &rhs)
	{
		insert(rhs, root);
	}
	void remove(const type &rhs)
	{
		remove(rhs, root);
	}

private:
	struct binary_node{
		type data;
		struct binary_node *left;
		struct binary_node *right;
		binary_node(const type &element, binary_node *le, binary_node *rt):
			data(element), left(le), right(rt) { }
	};
	binary_node *root;
	void insert(const type &x, binary_node * &t) const
	{
		if (t == NULL) {
			t = new binary_node(x, NULL, NULL);
		} else if (x <= t->data){
			insert(x, t->left);
		} else if (x > t->data) {
			insert(x, t->right);
		}
	}
	binary_node * find_min(binary_node * &t) const 
	{
		if (t == NULL) {
			return NULL;
		} else if (t->left == NULL){
			return t;
		} 
		return find_min(t->left);
	}
	binary_node *find_max(binary_node * &t) const 
	{
		if (t == NULL) {
			return NULL;
		} else if (t->right == NULL)  {
			return t;
		}

		return find_max(t->right);
	}
	void remove(const type &x, binary_node * &t) const
	{
		if (t == NULL) {
			return;
		} 
		if (x < t->data) {
			remove(x, t->left);
		} else if (x > t->data) {
			remove(x, t->right);
		} else if (t->right != NULL && t->left != NULL) {
			t->data = find_min(t->right)->data;
			remove(t->data, t->right);
		} else {
			binary_node *old_order = t;
			t = (t->right == NULL)? t->left :t->right;
			delete old_order;
		}
	}
	void printtree(binary_node * &t, int i =0) const
	{
		
	}
	void make_empty(binary_node * & t) const 
	{
		if (t != NULL) {
			make_empty(t->left);
			make_empty(t->right);
			delete t;
		}
	}
	binary_node * clone(binary_node *t) const
	{
		if (t == NULL) {
			return NULL;	
		}

		return new binary_node(t->data, t->left, t->right);
	}
};

int main(int argc, char *argv[])
{
	return 0;
}
