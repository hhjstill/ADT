#include <stdio.h>
#include "doublelinklist.h"
int main()
{
	CDList dList;
	for (int i = 0; i < 5; i++)
		dList.insertHead(i);
	for (int i = 0; i < 5; i++)
		dList.insertTail(i);
	dList.insert(1, 100);
	return 0;
}