// linklist.cpp : �������̨Ӧ�ó������ڵ㡣
// �����û������ҵ������е�n���ڵ�:
// 1.���ù���ָ��ָ���һ���ڵ�
// 2.��˶�Ӧ�����ü�����Ϊ1����Ӧ�����ڵ�
// 3.��������С��nʱ������ָ����ƣ���������1��
// 4.���˳�ѭ���������Ǽ���������nʱ���ҵ��ýڵ�

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

