/*
 * =====================================================================================
 *
 *       Filename:  spmutex.cpp
 *
 *    Description:  c++实现生产者消费者模型
 *
 *        Version:  1.0
 *        Created:  2014年11月12日 19时07分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */


/*
 *一个线程负责生产，一个线程负责消费
 *利用全局变量在线程中是共享的原理
 *
 */

#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

vector<int> contain(0,10);
static int ptr = 0;

void thread_work(void *n)
{
	if (ptr == 0) {
		int i = 0;
		for (i = 0; i < contain.size(); ++i) {
			contain.push_back(i);
		}
	}
}
void thread_work(void *n)
{
	if (ptr == 0) {
		return ;
	}

	cout << contain[0] << endl;
	ptr -= 1;
}
int main(int argc, char *argv[])
{
	pthread_t pid[2];
	
	pthread_create(pid, NULL, thread_work, NULL);
	pthread_create(pid + 1, NULL, thread_work1, NULL);
	return 0;
}
