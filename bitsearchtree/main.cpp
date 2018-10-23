#include "bitSearchTree.h"
#include <cstdio>
#include <stdlib.h>
#include <time.h>
int main()
{
	CBitSTree tObj;
	srand((unsigned int)time(0));
	for (int i = 0; i < 10; i++)
	{
		int nNum = rand() % 20 + 1;
		tObj.insert(nNum);
		tObj.show();
	}
	
	return 0;
}