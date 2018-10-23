#include "sequencelist.h"

int main()
{
	CSeqList list;
	CSeqList list2;
	list.initList();
	list2.initList();
	list.insert(1, 1);
	list.insert(1, 2);
	list.insert(1, 3);
	list.insert(1, 4);
	list.insert(1, 1);
	list.insert(1, 2);
	list.insert(1, 3);
	list.insert(1, 4);
	list.insert(1, 1);
	list.insert(1, 2);
	list.insert(1, 3);
	list.insert(1, 4);
	list.insert(1, 1);
	list.insert(1, 2);
	list.insert(1, 3);
	list.insert(1, 4);
	list.insert(1, 1);
	list.insert(1, 2);
	list.insert(1, 3);
	list.insert(1, 4);
	list[0] = 0;
	list.insertHead(100);
	list.insertTail(100);
	list.popback();
	for (int i = 0; i < 5; i++)
	{
		list2.insertHead(i);
	}
	cout << list << list2;
	return 0;
}