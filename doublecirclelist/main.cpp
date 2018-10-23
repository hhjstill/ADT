#include "dcirclelist.h"

int main()
{
	CDoubleCircleList dCircleList;
	for(int i = 0; i < 5; i++)
		dCircleList.insertHead(i);
	for (int i = 0; i < 5; i++)
		dCircleList.insertTail(i);
	dCircleList.insert(11, 123);
	dCircleList.erase(10);
	return 0;
}