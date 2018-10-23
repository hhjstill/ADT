// linklist.cpp : 定义控制台应用程序的入口点。
// 根据用户需求找到链表中第n个节点:
// 1.设置工作指针指向第一个节点
// 2.与此对应，设置计数器为1，对应工作节点
// 3.当计数器小于n时，工作指针后移，计数器加1。
// 4.当退出循环的条件是计数器等于n时即找到该节点

#include "stdafx.h"
#include "linklist.h"

int main()
{
	CLinkList list;
	for(int i = 0; i < 5; i++)
		list.insertTail(i);
	//list.insertBehind(6, 100);
	list.erase(5);
	int e = 0;
	list.getElem(2, e);
	int res = list.elemLocate(4);
	return 0;
}

